#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist[n];
        map<int, vector<pair<int, int>>> graph, graph_inc;
        int val;

        for(int i = 0; i < n; i++) {
            graph[i] = {};
            graph_inc[i] = {};
            dist[i] = vector<int>(k+1);
            for(int j = 0; j <= k; j++)
                dist[i][j] = INT_MAX;
        }

        for(auto& edge: flights) {
            graph[edge.at(0)].emplace_back(edge.at(1), edge.at(2));
            graph_inc[edge.at(1)].emplace_back(edge.at(0), edge.at(2));
        }

        dist[src][0] = 0;
        for(auto& pair: graph.at(src))
            dist[pair.first][0] = pair.second;

        for(int j = 1; j <= k; j++){
            for(int i = 0; i < n; i++){
                dist[i][j] = dist[i][j-1];

                for(auto v: graph_inc.at(i)){
                    if(dist[v.first][j-1] < INT_MAX){
                        val = v.second + dist[v.first][j-1];
                        if(val < dist[i][j])
                            dist[i][j] = val;
                    }
                }
            }
        }

        return (dist[dst][k] != INT_MAX ? dist[dst][k] : -1);
    }
};

int main(){

    Solution s;

    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout << s.findCheapestPrice(n, flights, src, dst, k) << endl;

    n = 3, src = 0, dst = 2, k = 1;
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << s.findCheapestPrice(n, flights, src, dst, k) << endl;

    n = 3, src = 0, dst = 2, k = 0;
    flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    cout << s.findCheapestPrice(n, flights, src, dst, k) << endl;

    n = 4, src = 0, dst = 3, k = 1;
    flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
    cout << s.findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}