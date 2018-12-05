// baekjoon 2644 yechan
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, s, e, m, dist[101];
vector<int> adj[101];

int main() {
	scanf("%d %d %d %d", &n, &s, &e, &m);

	for (int i=0; i<m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	queue<int> q;

	q.push(s);
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (int &next: adj[curr]) {
			if (!dist[next]) {
				dist[next] = dist[curr] + 1;
				q.push(next);
			}
		}
	}

	if (!dist[e]) 	printf("-1\n");
	else 			printf("%d\n", dist[e]);

	return 0;
}