#include <iostream>

using namespace std;

int main(){

    unsigned int N, K, a, b;
    cin >> N >> K;

    auto *** dp = new unsigned int ** [N];
    auto ** room = new unsigned int*[N];

    for(unsigned int i = 0; i < N; i++){
        dp[i] = new unsigned int * [K+1];
        for(unsigned int j = 0; j <= K; j++) {
            dp[i][j] = new unsigned int[3];
            for(unsigned int k = 0; k < 3; k++)
                dp[i][j][k] = 0;
        }
    }

    for(unsigned int i = 0; i < N; i++)
        room[i] = new unsigned int [2];

    unsigned int i = 0;
    cin >> a >> b;
    while(a && b){
        room[i][0] = a;
        room[i][1] = b;
        i += 1;
        cin >> a >> b;
    }

    dp[0][0][0] = room[0][0]+room[0][1];
    dp[0][1][1] = room[0][0];
    dp[0][1][2] = room[0][1];

    for(i = 1; i < N; i++)
        for(unsigned int j = 0; j <= K; j++){

            dp[i][j][0] = room[i][0]+room[i][1];
            auto max = dp[i-1][j][0];
            if(max < dp[i-1][j][1])
                max = dp[i-1][j][1];
            if(max < dp[i-1][j][2])
                max = dp[i-1][j][2];
            dp[i][j][0] += max;

            if (j > 0) {
                dp[i][j][1] = room[i][0] + dp[i - 1][j - 1][1];
                dp[i][j][2] = room[i][1] + dp[i - 1][j - 1][2];
            }
        }

    auto max = dp[N-1][K][0];
    if(max < dp[N-1][K][1])
        max = dp[N-1][K][1];
    if(max < dp[N-1][K][2])
        max = dp[N-1][K][2];

    cout << max << "\n";

    free(dp);
    free(room);
    return 0;
}