// baekjoon 5719 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

int n, m, s, d, u, v, w;
int adj[502][502];
int dist[502];

void dijkstra() {
	memset(dist, -1, sizeof(dist));
	priority_queue<P> pq;
	pq.push(P(0, s));
	while (!pq.empty()){
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[here] != -1) continue;
		dist[here] = cost;
		for (int i=0; i<n; i++) {
			if (adj[here][i] == -1) continue;
			if (dist[i] != -1) continue;
			pq.push(P(-cost-adj[here][i], i));
		}
	}
}

void erasePath() {
	queue<int> q;
	q.push(d);
	while (!q.empty()) {
		int here = q.front(); q.pop();
		for (int i=0; i<n; i++) {
			if (dist[i]+adj[i][here] == dist[here] && adj[i][here] != -1) {
				adj[i][here] = -1;
				q.push(i);
			}
		}
	}
}

int main() {

	while (1) {
		scanf("%d%d", &n, &m);
		if (n==0 && m ==0) break;
		scanf("%d%d", &s, &d);
		memset(adj, -1, sizeof(adj));
		for (int i=0; i<m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			adj[u][v] = w;
		}
		dijkstra();
		erasePath();
		dijkstra();
		printf("%d\n", dist[d]);
	}
	return 0;
}