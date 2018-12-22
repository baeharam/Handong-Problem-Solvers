#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int n,m,s,d,u,v,p;
int adj[502][502];
int dp[502];

void dijkstra() {
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int,int> > pq;
    pq.push({ 0,s });
    while (pq.size()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dp[here] != -1)continue;
        dp[here] = cost;
        for (int i = 0; i < n; i++) {
            if (adj[here][i] == -1)continue;
            if (dp[i] != -1)continue;
            pq.push({ -cost - adj[here][i],i });
        }
    }
}
void eraseEdge() {
    queue<int> qu;
    qu.push(d);
    while (qu.size()) {
        int cx = qu.front();
        qu.pop();
        for (int i = 0; i < n; i++) {
            if (dp[cx] == dp[i] + adj[i][cx] && adj[i][cx] != -1) {
                adj[i][cx] = -1;
                qu.push(i);
            }    
        }
    }
}

int main() {
  while(1){
    cin >> n >> m;
    if(n==0&&m==0) break;
    cin >> s >> d;
    memset(adj, -1, sizeof(adj));
    for(int i=0; i<m; i++){
      cin >> u >> v >> p;
      adj[u][v] = p;
    }
    dijkstra();
    eraseEdge();
    dijkstra();
    cout << dp[d] << endl;
  }
  
}