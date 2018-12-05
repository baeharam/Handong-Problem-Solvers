#include <cstdio>
#include <vector>

int n,v1,v2,m,x,y,ans;
int visit[101];
std::vector<int> g[101];

void dfs(int v, int chonsu){
    if(v==v2) ans = chonsu;
    visit[v] = 1;
    for(int i=0; i<g[v].size(); i++){
        if(!visit[g[v][i]]) 
            dfs(g[v][i],chonsu+1);
    }
}

int main(void)
{
    scanf("%d%d%d%d",&n,&v1,&v2,&m);
    for(int i=0; i<m; i++){
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ans = -1;
    dfs(v1,0);
    printf("%d",ans);
    return 0;
}