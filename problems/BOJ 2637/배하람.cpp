#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

vector<pii> g[101];
int n,m,_x,_y,k;
int dp[101][101];
int visit[101];

int dfs(int v, int res)
{
    if(g[v].size()) visit[v] = 1;

    for(int i=0; i<g[v].size(); i++){
        int next = g[v][i].first;
        int num = g[v][i].second;

        if(g[next].size()){
            dp[v][res] += (visit[next] ? dp[next][res] : dfs(next,res)) * num;
        }
    }
    return dp[v][res];
}

int main(void)
{
    scanf("%d%d",&n,&m);

    for(int i=0; i<m; i++){
        scanf("%d%d%d",&_x,&_y,&k);
        g[_x].push_back({_y,k});
        dp[_x][_y] = k;
    }

    for(int i=1; i<n; i++){
        if(!g[i].size()){
            printf("%d %d\n", i, dfs(n,i));
            memset(visit,0,sizeof(visit));
        }
    }

    return 0;
}