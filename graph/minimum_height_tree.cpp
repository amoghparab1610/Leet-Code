#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    set<int> findCenters(int n, vector<set<int>>& edges) {
        set<int> centers;
        int degree[n];

        for(int i = 0; i < n; i++){
            centers.insert(i);
            degree[i] = edges.at(i).size();
        }

        while(centers.size() > 2){

            vector<int> degree_one_vertices;
            for(auto u: centers){
                if(degree[u] == 1)
                    degree_one_vertices.push_back(u);
            }

            for(auto u: degree_one_vertices){

                auto v = *edges.at(u).begin();
                edges.at(u).erase(v);
                edges.at(v).erase(u);

                degree[u] -= 1;
                degree[v] -= 1;
                centers.erase(u);
            }
        }

        return centers;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<set<int>> all_edges(n);
        int u, v;

        for(auto& edge: edges){
            u = edge.at(0);
            v = edge.at(1);
            all_edges.at(u).emplace(v);
            all_edges.at(v).emplace(u);
        }

        auto c = findCenters(n, all_edges);
        vector<int> centers{c.begin(), c.end()};

        return centers;
    }
};

int main(){

    Solution s;
    int n, e, u, v;
    cin >> n;

    e = n-1;
    vector<vector<int>> graph(n-1);
    while(e > 0){
        cin >> u >> v;
        graph.push_back({u, v});
        e--;
    }

    auto centers = s.findMinHeightTrees(n, graph);

    for(auto center: centers)
        cout << center << " ";
    cout << endl;

    return 0;
}