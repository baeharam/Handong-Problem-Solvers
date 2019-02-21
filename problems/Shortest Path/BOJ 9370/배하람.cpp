#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

int tc,n,m,t,s,g,h,a,b,d,p;
int sps[2001],spg[2001],sph[2001],vi[2001];
const int INF = 2e9;
priority_queue<pii,vector<pii>,greater<pii>> pq;

void dijk(pii src, int *sp, vector<pii> *graph)
{
    for(int i=1; i<=n; i++) {
        sp[i] = INF;
        vi[i] = 0;
    }
    sp[src.second] = 0;
    pq.push(src);

    while(!pq.empty()) {
        pii v = pq.top(); pq.pop();
        vi[v.second] = 1;
        for(int i=0; i<graph[v.second].size(); i++){
            int next = graph[v.second][i].second;
            if(!vi[next] && sp[v.second]+graph[v.second][i].first < sp[next]){
                sp[next] = sp[v.second]+graph[v.second][i].first;
                pq.push({sp[next],next});
            }
        }
    }
}

int main(void)
{
    scanf("%d",&tc);

    while(tc--) {
        vector<pii> graph[2001];
        vector<int> candidate,ans;

        scanf("%d%d%d",&n,&m,&t);
        scanf("%d%d%d",&s,&g,&h);

        for(int i=0; i<m; i++){
            scanf("%d%d%d",&a,&b,&d);
            graph[a].push_back({d,b});
            graph[b].push_back({d,a});
            if((a==g && b==h)||(a==h && b==g)) p = d;
        }
        candidate.resize(t);
        for(int i=0; i<t; i++){
            scanf("%d",&candidate[i]);
        }

        dijk({0,s},sps,graph);
        dijk({0,g},spg,graph);
        dijk({0,h},sph,graph);

        for(int i=0; i<candidate.size(); i++){
            int org = sps[candidate[i]];
            int firstPath1 = sps[g];
            int firstPath2 = sps[h];
            int secondPath1 = sph[candidate[i]];
            int secondPath2 = spg[candidate[i]];
            int path1 = firstPath1+p+secondPath1;
            int path2 = firstPath2+p+secondPath2;
            int path = path1<path2?path1:path2;

            if(org==path) ans.push_back(candidate[i]);
        }
        sort(ans.begin(),ans.end());
        for(auto vertex : ans) printf("%d ",vertex);
        
        puts("");
    }

    return 0;
}