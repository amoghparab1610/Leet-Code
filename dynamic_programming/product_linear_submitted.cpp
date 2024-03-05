#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B) {
    // Implement your solution here

    int d = B.size(), n = A.size(), neighbours = 9;
    vector<int> d_product(d);
    double sum;

    d_product[d-1] = 1;
    for(int i = d-2; i >= 0; i--)
        d_product[i] = d_product[i+1]*B[i+1];

    vector<int> result;
    for(int i = 0; i < n; i++){

        sum = A[i];

        for(int j = 0; j < d; j++){

            if(i+d_product[j] < n)
                sum += A[i+d_product[j]];
            if(i-d_product[j] >= 0)
                sum += A[i-d_product[j]];
        }

        result.push_back(round(sum/neighbours));
    }
    return result;
}

int main(){
    /*
    vector<int> A = {44, 14, 92, 6}, B = {2, 2, 1, 1};
     **/
    vector<int> A = {49, 91, 71, 33, 4, 113}, B = {1, 1, 1, 6};
    auto result = solution(A, B);
    return 0;
}