#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 100000000
using namespace std;

int dp[16][1 << 16];
int w[16][16];
int N;

int dfs(int n, int v)
{
    if (dp[n][v] != -1) return dp[n][v];
    if (v == (1 << N) - 1)
    {
        if (w[n][0] != 0) return w[n][0];
        return INF;
    }
    dp[n][v] = INF;

    for (int i = 0; i < N; i++)
    {
        if ((v&(1 << i)) || w[n][i] == 0) continue;

        dp[n][v] = min(dp[n][v], dfs(i, v | (1 << i)) + w[n][i]);
    }
    return dp[n][v];
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> w[i][j];
    memset(dp, -1, sizeof(dp));

    printf("%d\n", dfs(0, 1));
}
