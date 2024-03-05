#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int find_cycle(int u, vector<int>* graph, bool* visited, bool* explored, int* cycle){

        visited[u] = true;
        explored[u] = true;

        for(auto v: graph[u]){
            if(visited[v])
                return 1;
            if(cycle[v] == -1)
                cycle[v] = find_cycle(v, graph, visited, explored, cycle);
            if(cycle[v] == 1)
                return 1;
        }

        visited[u] = false;
        return 0;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        bool visited[numCourses], explored[numCourses];
        int cycle[numCourses];
        vector<int> graph[numCourses];

        for(const auto& preq : prerequisites)
            graph[preq.at(0)].push_back(preq.at(1));

        for(int i = 0; i < numCourses; i++) {
            visited[i] = false;
            explored[i] = false;
            cycle[i] = -1;
        }

        int start = 0;
        while(start < numCourses){
            if(find_cycle(start, graph, visited, explored, cycle))
                return false;
            while(start < numCourses && explored[start])
                start++;
        }
        return true;
    }
};

int main(){

    /* Find cycle in directed graph. If cycle is present, cannot finish
     * Graph may be disconnected
     **/
    int n, x, y, p;
    vector<vector<int>> prerequisites;
    Solution s;

    cin >> n >> p;
    while(p > 0){
        cin >> x >> y;
        prerequisites.push_back({x, y});
        p--;
    }

    cout << s.canFinish(n, prerequisites) << endl;

    return 0;
}