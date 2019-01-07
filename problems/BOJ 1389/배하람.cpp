#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int adj[101][101];
int dp[101][101];

int n,m,v1,v2;

int main(void)
{
    scanf("%d%d",&n,&m);
    fill(adj[0],adj[0]+101*101,2e8);
    for(int i=0; i<m; i++){
        scanf("%d%d",&v1,&v2);
        adj[v1][v2]=1;
        adj[v2][v1]=1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    int _max = 2e8;
    int ans = 0;
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            sum += adj[i][j];
        }
        if(_max>sum){
            _max = sum;
            ans = i;
        }
    }
    printf("%d",ans);
    return 0;
}