#include <iostream>
#include <cfloat>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {

    int n = 0;
    map<string, int> id;
    vector<vector<double>> edges;
    vector<vector<vector<double>>> dist;

    void initialize(vector<vector<string>>& equations, vector<double>& values){

        double val;
        string u, v;

        for(auto eq: equations){

            u = eq.front();
            v = eq.back();

            if(id.find(u) == id.end())
                id.emplace(u, n++);
            if(id.find(v) == id.end())
                id.emplace(v, n++);
        }

        for(int i = 0; i < n; i++)
            edges.emplace_back(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                edges[i][j] = 0;
            edges[i][i] = 1;
        }

        for(int i = 0; i < equations.size(); i++){

            u = equations.at(i).front();
            v = equations.at(i).back();
            val = values.at(i);

            edges[id[u]][id[v]] = val;
            edges[id[v]][id[u]] = 1/val;
        }
    }

    void evaluate(){
        for(int i = 0; i < n; i++){
            dist.emplace_back();
            for(int j = 0; j < n; j++){
                dist[i].emplace_back();
                for(int k = 0; k <= n; k++)
                    dist[i][j].emplace_back(0);
            }
        }

        for(int i = 0; i < n; i ++)
            for (int j = 0; j < n; j++)
                dist[i][j][0] = (edges[i][j] > 0 ? edges[i][j] : DBL_MAX);

        for (unsigned int k = 1; k <= n; k++)
            for(unsigned int i = 0; i < n; i ++)
                for (unsigned int j = 0; j < n; j++){

                    dist[i][j][k] = dist[i][j][k-1];

                    if(dist[i][k-1][k-1] == DBL_MAX || dist[k-1][j][k-1] == DBL_MAX)
                        continue;

                    auto newDist = dist[i][k-1][k-1] * dist[k-1][j][k-1];
                    if(newDist < dist[i][j][k])
                        dist[i][j][k] = newDist;
                }
    }

    vector<double> evaluate_queries(vector<vector<string>>& queries){

        string u, v;
        vector<double> result;

        for(auto query: queries){

            u = query.front();
            v = query.back();

            if((id.find(u) == id.end()) || (id.find(v) == id.end()) || dist[id[u]][id[v]][n] == DBL_MAX)
                result.push_back(-1);
            else
                result.push_back(dist[id[u]][id[v]][n]);
        }

        return result;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        initialize(equations, values);
        evaluate();
        return evaluate_queries(queries);
    }
};

int main(){
    string x, y;
    int edges, num_queries;
    double val;
    cin >> edges;

    vector<vector<string>> equations(edges);
    vector<double> values(edges);

    for(int i = 0; i < edges; i++){
        cin >> x >> y;
        equations[i] = {x, y};
    }
    for(int i = 0; i < edges; i++){
        cin >> val;
        values[i] = val;
    }

    cin >> num_queries;
    vector<vector<string>> queries(num_queries);

    for(int i = 0; i < num_queries; i++){
        cin >> x >> y;
        queries[i] = {x, y};
    }

    Solution s;
    auto result = s.calcEquation(equations, values, queries);
    for(auto res: result)
        cout << res << " ";
    cout << endl;

    return 0;
}