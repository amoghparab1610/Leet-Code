#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int get_group(int node, int* group){

        int x = node;
        while(group[x] != x)
            x = group[x];
        return x;
    }

    void merge_groups(int id1, int id2, int* group, int* count){
        if(count[id1] <= count[id2]){
            group[id1] = id2;
            count[id2] += count[id1];
        }else{
            group[id2] = id1;
            count[id1] += count[id2];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size(), u, v, id_u, id_v;
        int group[n+1], count[n+1];

        for(int i = 0; i <= n; i++) {
            group[i] = i;
            count[i] = 1;
        }

        for(int i = 0; i < n; i++){

            const auto& edge = edges.at(i);
            u = edge.front();
            v = edge.back();

            id_u = get_group(u, group);
            id_v = get_group(v, group);

            if(id_u == id_v)
                return {u, v};

            merge_groups(id_u, id_v, group, count);
        }

        return {0, 0};
    }
};

int main(){

    int n, x, y;
    cin >> n;

    vector<vector<int>> edges(n);
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        edges[i] = {x, y};
    }

    Solution s;
    auto edge = s.findRedundantConnection(edges);
    cout << edge.front() << ", " << edge.back() << endl;

    return 0;
}