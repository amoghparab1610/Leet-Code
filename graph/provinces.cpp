#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int u, int n, vector<vector<int>>& isConnected, bool* visited){

        visited[u] = true;
        for(int i = 0; i < n; i++)
            if(isConnected.at(u).at(i) == 1 && !visited[i])
                dfs(i, n, isConnected, visited);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size(), provinces = 0;
        bool visited[n];

        for(int i = 0; i < n; i++)
            visited[i] = false;

        int start = 0;
        while(start < n){

            provinces += 1;
            dfs(start, n, isConnected, visited);

            while(start < n && visited[start])
                start++;
        }

        return provinces;
    }
};

int main(){

    int n, x;
    cin >> n;

    // Find number of connected components in undirected graph
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> x;
            graph.at(i).push_back(x);
        }

    Solution s;
    cout << s.findCircleNum(graph) << endl;

    return 0;
}