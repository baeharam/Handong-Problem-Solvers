#include <cstdio>
#include <algorithm>

int n;
int w[17][17];
int dp[17][1<<17];
const int INF = 2100000000;

int tsp(int v, int visit)
{
    // 메모이제이션이 되어 있는 값은 그 값 리턴
    if(dp[v][visit]) return dp[v][visit];

    // 모든 마을을 방문했을 때 마지막 마을로부터 출발지까지 경로가 있으면 그 값을 아니면 INF 리턴
    if(visit == (1<<n) - 1) return w[v][1] ? w[v][1] : INF;

    // 현재 방문상태인 visit에서 마지막으로 v를 방문한 경우의 최소비용을 구하는 부분
    dp[v][visit] = INF;
    for(int i=1; i<=n; i++){
        // 해당 마을을 방문하지 않은 상태이고 그 마을에 대한 경로가 존재하면
        // 방문한 상태로 변화시킨 후에 tsp 재귀 호출, 메모이제이션 값은 계속 업데이트
        if(!(visit & 1<<(i-1)) && w[v][i])
            dp[v][visit] = std::min(dp[v][visit], tsp(i,visit|(1<<i-1)) + w[v][i]);
    }    
    return dp[v][visit];
}

int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            scanf("%d",&w[i][j]);
    }

    printf("%d\n",tsp(1,1));
    
    return 0;
}