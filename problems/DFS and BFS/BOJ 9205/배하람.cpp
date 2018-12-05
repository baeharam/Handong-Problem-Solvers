#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

inline int dist(int x1, int y1, int x2, int y2){
    int dist_x = x1<x2?(x2-x1):(x1-x2);
    int dist_y = y1<y2?(y2-y1):(y1-y2);
    return dist_x+dist_y;
}

int tc,n;
int visit[105];
pair<int,int> coor[105];
vector<int> g[105];

bool dfs(int v)
{
    if(v==n-1) return true;
    visit[v]=1;
    for(int i=0; i<g[v].size(); i++){
        int d = dist(coor[v].first,coor[v].second,coor[g[v][i]].first,coor[g[v][i]].second);
        if(!visit[g[v][i]] && d<=1000){ 
            if(dfs(g[v][i])) return true;
        }
    }
    return false;
}

int main(void)
{
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n); n+=2;
        for(int i=0; i<n; i++)
            scanf("%d%d",&coor[i].first,&coor[i].second);

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }

        dfs(0) ? printf("happy") : printf("sad"); printf("\n");

        for(int i=0; i<n; i++){
            visit[i]=0;
            g[i].clear();
        }
    }
    return 0;
}