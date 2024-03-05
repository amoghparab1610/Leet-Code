#include <iostream>

using namespace std;

int main(){

    unsigned int N, W, H;
    unsigned long long m = 1000000007;
    cin >> N >> W >> H;

    auto ** dp = new unsigned long *[W+1];
    for(unsigned int i = 0; i <= W; i++)
        dp[i] = new unsigned long [N+1];

    for(unsigned int j = 0; j <= N; j++)
        dp[1][j] = (j >= H ? H+1 : j+1);

    for(unsigned int i = 2; i <= W; i++)
        for(unsigned int j = 0; j <= N; j++) {
            dp[i][j] = 0;
            for(unsigned int k = 0; k <= H; k++)
                if(j >= k)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k])%m;
        }

    unsigned long long flat = 0, ribbon_used = 0;
    while(ribbon_used <= N){
        ribbon_used += W;
        flat += 1;
    }

    cout << (dp[W][N] - flat)%m << "\n";

    free(dp);
    return 0;
}