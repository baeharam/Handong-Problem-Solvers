#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n,v1,v2;
int w[10001],visit[10001],dp[10001][2];
vector<int> g[10001],set[10001][2];
vector<int> ans;

void dfs(int v)
{
    visit[v] = 1;
    dp[v][0] = w[v];
    //set[v][0].push_back(v);

    for(int i=0; i<g[v].size(); i++){
        int next = g[v][i];
        if(!visit[next]){
            dfs(next);
            dp[v][0] += dp[next][1];
            //for(int j=0; j<set[next][1].size(); j++) set[v][0].push_back(set[next][1][j]);

            if(dp[next][0]>dp[next][1]){
                dp[v][1] += dp[next][0];
                //for(int j=0; j<set[next][0].size(); j++) set[v][1].push_back(set[next][0][j]);
            } else{
                dp[v][1] += dp[next][1];
                //for(int j=0; j<set[next][1].size(); j++) set[v][1].push_back(set[next][1][j]);
            }
        }
    }
}

void addSet(int prev, int here, int state)
{
    if(!state){
        ans.push_back(here);
        for(auto child : g[here]){
            if(prev==child) continue;
            addSet(here,child,1);
        }
    }
    else{
        for(auto child : g[here]){
            if(prev==child) continue;
            printf("%d\n",child);
            if(dp[child][0]>dp[child][1])
                addSet(here,child,0);
            else
                addSet(here,child,1);
        }
    }
}


int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&w[i]);
    while(scanf("%d%d",&v1,&v2)!=EOF){
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    dp[1][0]>dp[1][1] ? addSet(-1,1,0) : addSet(-1,1,1);
    //sort(set[1][0].begin(),set[1][0].end());
    //sort(set[1][1].begin(),set[1][1].end());

    sort(ans.begin(), ans.end());

    printf("%d\n",max(dp[1][0],dp[1][1]));
    // if(dp[1][0]>dp[1][1]){
    //     for(int i=0; i<set[1][0].size(); i++)
    //         printf("%d ",set[1][0][i]);
    // } else{
    //     for(int i=0; i<set[1][1].size(); i++)
    //         printf("%d ",set[1][1][i]);
    // }

    for(auto node : ans) printf("%d ",node);

    return 0;
}