#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 100000000;
int N, W[16][16];
int dp[16][1 << 16];

int TSP(int current, int visited)
{
    if(dp[current][visited] != -1) return dp[current][visited];

    if(visited == (1 << N) - 1){    // 모든 마을을 방문했을 경우 (1 << N) - 1 --> 전체 집합
        if(W[current][0] != 0) return W[current][0];
        return INF;         // 처음 마을로 돌아갈 수 없는 경우
    }
    int ret = INF;
    for(int i = 0; i < N; i++){
        if(visited & (1 << i) || W[current][i] == 0) // 방문했었을 경우 또는 아직 방문하지 않았던 경우 
            continue;
        ret = min(ret, TSP(i, visited | (1 << i) ) + W[current][i]); 
    }
    return dp[current][visited] = ret; // momoization
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);

    memset(dp, -1, sizeof(dp));
    printf("%d", TSP(0,1));

    return 0;
}