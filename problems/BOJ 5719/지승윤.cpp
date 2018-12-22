#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m,s,e;
int dist[504];
int check[504][504];
vector<vector<pair<int, int>>> vt;
vector<vector<pair<int, int>>> rvt;
queue<int> qu;
priority_queue<pair<int, int>> pq;

void dij(){
    memset(dist,-1,sizeof(dist));
    pq.push({0,s});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        
        if(dist[here] != -1) continue;
        dist[here] = cost;
        
        for (int i = 0; i < vt[here].size(); i++) {
            int ncost = cost + vt[here][i].second;
            int there = vt[here][i].first;
            
            if(check[here][there] == -1) {
                continue;
                
            }
            
            if(dist[there] == -1) pq.push({-ncost,there});
        }
    }
}

void checkLine(){
    qu.push(e);
    while (!qu.empty()) {
        int now = qu.front();
        qu.pop();
        
        for (int i = 0; i < rvt[now].size(); i++) {
            int previous = rvt[now][i].first;
            int cost = rvt[now][i].second;
            
            if(dist[now] == dist[previous] + cost){
                qu.push(previous);
                check[previous][now] = -1;
            }
        }
    }
}


int main(){
    while(scanf("%d %d" , &n,&m)){
        if(n==0 && m==0) break;
        vt.clear();
        rvt.clear();
        vt.resize(n+1);
        rvt.resize(n+1);
        scanf("%d %d" , &s,&e);
        for(int i = 0; i<=n ; i++) memset(check[i],0,sizeof(check[i]));
        for (int i = 0; i < m; i++) {
            int a,b,c;
            scanf("%d %d %d" , &a,&b,&c);
            vt[a].push_back({b,c});
            rvt[b].push_back({a,c});
        }
        
        dij();
        checkLine();
        dij();

        printf("%d\n" , dist[e]);
    }
}

