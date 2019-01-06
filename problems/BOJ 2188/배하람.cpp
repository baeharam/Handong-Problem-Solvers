#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n,m,s,num,ans;
int cowToHome[201],homeToCow[201],visited[201];
vector<int> adj[201];


bool dfs(int v)
{
    visited[v] = 1;
    // 소가 갈 수 있는 축사들 체크
    for(int i=0; i<adj[v].size(); i++){
        int home = adj[v][i];
        // 1. 축사가 비어있는 경우
        // 2. 축사가 차있지만 해당 소가 다른 축사로 이동할 수 있는 경우
        if(!homeToCow[home] || !visited[homeToCow[home]] && dfs(homeToCow[home])){
            homeToCow[home] = v;
            cowToHome[v] = home;
            return true;
        }
    }
    return false;
}

int main(void)
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%d",&s);
        while(s--){
            scanf("%d",&num);
            adj[i].push_back(num);
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        // 소가 축사에 들어가지 못한경우
        if(!cowToHome[i]){
            memset(visited,0,sizeof(visited));
            // 소가 축사에 들어갔으면 증가
            if(dfs(i)) ans++;
        }
    }
    printf("%d",ans);

    return 0;
}