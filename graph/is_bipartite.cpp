#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int u, bool id, vector<vector<int>>& graph, bool* visited, bool* group){

        bool result;
        visited[u] = true;
        group[u] = id;

        for(auto v: graph.at(u)){
            result = (visited[v] ? (group[u] == group[v]) : !dfs(v, !group[u], graph, visited, group));
            if(result)
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size(), start = 0;
        bool visited[n], group[n], result;

        for(int i = 0; i < n; i++) {
            visited[i] = false;
            group[i] = false;
        }

        while(start < n){

            result = dfs(start, true, graph, visited, group);
            if(!result)
                return false;

            while(start < n && visited[start])
                start++;
        }

        return true;
    }
};

int main(){

    // vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    Solution s;
    cout << s.isBipartite(graph) << endl;

    return 0;
}