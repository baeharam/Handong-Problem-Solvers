#include <cstdio>

int main(){

    int T;
    scanf("%d", &T);
    while (T--){
        int N, K;
        int dp[101][101][2] = { 0 };

        scanf("%d%d", &N, &K);
        dp[0][1][0] = dp[0][1][1]  = 1;

        for (int k = 0; k <= K; k++){
            for (int n = 2; n <= N; n++){
                if (k - 1 >= 0)
                    dp[k][n][1] += dp[k - 1][n - 1][1];

                dp[k][n][1] += dp[k][n - 1][0];
                dp[k][n][0] += dp[k][n - 1][1] + dp[k][n - 1][0];
            }
        }
        printf("%d\n", dp[K][N][0] + dp[K][N][1]);
    }
    return 0;
}
