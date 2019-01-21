#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define max 1000002

int dp[max][2];
bool visited[max];
vector<int> child[max];
vector<int> edge[max];

void getChild(int cur){
    visited[cur] = true;
    for(int i = 0; i < edge[cur].size(); i++){
        int next = edge[cur][i];
        if(!visited[next]){
            child[cur].push_back(next);
            getChild(next);
        }
    }
}

int getDp(int cur, bool adapter){
    if(dp[cur][adapter] != 0) return dp[cur][adapter];
    if(child[cur].size() == 0) return dp[cur][adapter] = adapter;
    if(adapter){
        int ans = 0;
        for(int i = 0; i < child[cur].size(); i++){
            int next = child[cur][i];
            ans += min(getDp(next, false), getDp(next, true));
        }
        return dp[cur][adapter] = ans+1;
    } else {
        int ans = 0;
        for(int i = 0; i < child[cur].size(); i++){
            int next = child[cur][i];
            ans += getDp(next, true);
        }
        return dp[cur][adapter] = ans;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    getChild(1);
    printf("%d", min(getDp(1, false), getDp(1, true)));

}