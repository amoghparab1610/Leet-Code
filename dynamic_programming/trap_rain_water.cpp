#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(), val, max_first_index, max, min, result, l, r;
        std::pair<int, int> left_pair, right_pair;
        vector<int> sum;
        vector<pair<int, int>> max_forward, max_backward;

        sum.push_back(height.front());
        max_forward.emplace_back(0, height.front());
        max_backward.emplace_back(n-1, height.back());
        max = height.front();

        for(int i = 1; i < n; i++){
            
            val = height.at(i);
            sum.push_back(sum[i-1]+val);
            
            if(max < val){
                max = val;
                max_forward.emplace_back(i, max);
            }
        }

        max = height.back();
        max_first_index = max_forward.back().first;

        for(int i = n-2; i >= max_first_index; i--){
            val = height.at(i);

            if(max < val){
                max = val;
                max_backward.emplace_back(i, max);
            }
        }

        result = 0;
        for(int i = 0; i < max_forward.size()-1; i++){
            
            left_pair = max_forward.at(i);
            right_pair = max_forward.at(i+1);
            l = left_pair.first;
            r = right_pair.first;

            if(r - l > 1){
                min = (left_pair.second < right_pair.second ? left_pair.second : right_pair.second);
                result += min * (r - l - 1) - (sum[r-1] - sum[l]);
            }
        }

        for(int i = 0; i < max_backward.size()-1; i++){
            
            left_pair = max_backward.at(i+1);
            right_pair = max_backward.at(i);
            l = left_pair.first;
            r = right_pair.first;

            if(r - l > 1){
                min = (left_pair.second < right_pair.second ? left_pair.second : right_pair.second);
                result += min * (r - l - 1) - (sum[r-1] - sum[l]);
            }
        }

        if(max_forward.empty() || max_backward.empty())
            return result;

        left_pair = max_forward.back();
        right_pair = max_backward.back();
        l = left_pair.first;
        r = right_pair.first;

        if(r - l > 1){
            min = (left_pair.second < right_pair.second ? left_pair.second : right_pair.second);
            result += min * (r - l - 1) - (sum[r-1] - sum[l]);
        }

        return result;
    }
};

int main(){

    int n, x;
    vector<int> height;
    Solution s;

    cin >> n;
    while(n > 0){
        cin >> x;
        height.push_back(x);
        n--;
    }

    cout << s.trap(height) << endl;

    return 0;
}