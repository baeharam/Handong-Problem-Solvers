#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int,int> pii;

priority_queue<pii,vector<pii>,greater<pii> > pq;
queue<int> q;
vector<pii > g[501];
vector<int> before[501];
int dist[501], visit[501];
int n,m,s,d,u,v,p;
const int INF = 210000000;

void init(){
    for(int i=0; i<=n; i++) {
        dist[i] = INF;
        visit[i] = 0;
    }
}

void dijk(int src){
    dist[src] = 0;
    pq.push({dist[src],src});
    while(!pq.empty()){
        int st = pq.top().second;
        pq.pop();
        if(!visit[st]){
            visit[st] = 1;
            for(int i=0; i<g[st].size(); i++){
                int sn = g[st][i].first;
                if(dist[st]+g[st][i].second < dist[sn]){
                    dist[sn] = dist[st] + g[st][i].second;
                    pq.push({dist[sn],sn});
                    before[sn].clear();
                    before[sn].push_back(st);
                }
                else if(dist[st]+g[st][i].second == dist[sn])
                    before[sn].push_back(st);
            }
        }
    }
}

void removeEdge(int d){
    q.push(d);
    while(!q.empty()){
        int n = q.front(); q.pop();
        for(int i=0; i<before[n].size(); i++){
            int _n = before[n][i];
            q.push(_n);
            for(int j=0; j<g[_n].size(); j++){
                if(g[_n][j].first==n){
                    g[_n][j].second = INF;
                    break;
                }
            }
        }
    }
}

int main(void)
{
    while(true){
        scanf("%d%d",&n,&m);
        if(!(n&&m)) break;
        scanf("%d%d",&s,&d);
        for(int i=0; i<m; i++){
            scanf("%d%d%d",&u,&v,&p);
            g[u].push_back({v,p});
        }

        init(); dijk(s);
        removeEdge(d);
        init(); dijk(s);

        dist[d] == INF ? puts("-1") : printf("%d\n",dist[d]);

        for(int i=0; i<=n; i++){
            g[i].clear();
            before[i].clear();
        }
    }
    return 0;
}