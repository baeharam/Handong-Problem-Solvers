//draft code
#include<bits/stdc++.h>
#define MV 2001
using namespace std;
typedef pair<int, int> P;
int tc, n, m, t, start, k, h, a, b, c, tmp, dist[MV];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>tc;
    while(tc--){
        bool visited[MV];
        vector<P> g[MV];
        priority_queue<P,vector<P>,greater<P> > pq;
        vector<int> candidate;
        cin>>n>>m>>t>>start>>k>>h;
        fill(visited,visited+n+1,false);
        for(int i = 0; i < m; i++){
            cin>>a>>b>>c;
            if((a == k && b == h)||(a == h && b == k)){
                g[a].push_back({b,c*2-1});
                g[b].push_back({a,c*2-1});
            }
            else{
                g[a].push_back({b,c*2});
                g[b].push_back({a,c*2});
            }
        }
        for(int i = 0 ; i < t; i++){
            cin>>tmp;
            candidate.push_back(tmp);
        }
        fill(dist,dist+n+1,1000000000);
        pq.push({0, start});
        dist[start] = 0;
        for(int i = 0; i < g[start].size(); i++)
            dist[g[start][i].first] = g[start][i].second;
        while(!pq.empty()){
            int here = pq.top().second;
            pq.pop();
            if(visited[here]) continue;
            visited[here] = true;
            for(int i = 0; i < g[here].size(); i++){
                    dist[g[here][i].first] = min(dist[g[here][i].first],dist[here]+g[here][i].second);
                    pq.push({dist[g[here][i].first],g[here][i].first});
		    }
        }
    sort(candidate.begin(),candidate.end()); 
	for(int i = 0; i < candidate.size(); i++)
		if((dist[candidate[i]]%2) == 1) cout<<candidate[i]<<" ";
    cout<<"\n";
    }
}
