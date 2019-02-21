// bakejoon 9370 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>
#include <vector>
using namespace std;
const int MAX_INF = 1e9;
typedef pair<int, int> P;

int T, n, m, t, s, g, h, a, b, d;
vector<vector<P>> adj;
vector<int> result;
vector<bool> visited;
vector<int> dist;

void Dijkstra(int start) {
	dist[start] = 0;
	priority_queue<P, vector<P>, greater<P> > PQ;
	PQ.push(P(0, start));

	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]);
		if (visited[curr]) break;
		visited[curr]=true;
		for (auto &p: adj[curr]) {
			int next=p.first, d=p.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}
}

bool tracking(int start) {
	if (dist[start] == 0) return false;
	if (dist[start] == MAX_INF) return false;
	bool ret=false;
	for (auto &p: adj[start]) {
		int next=p.first, d=p.second;
		if (dist[next] == dist[start]-d) {
			if (start == g && next == h) return true;
			if (start == h && next == g) return true;
			ret |= tracking(next);
		}
	}
	return ret;
}


int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &t);
		scanf("%d%d%d", &s, &g, &h);

		result.clear();
		adj = vector<vector<P> >(n+1);
		visited = vector<bool>(n+1, false);
		dist = vector<int>(n+1, MAX_INF);
		for (int i=0; i<m; i++) {
			scanf("%d%d%d", &a, &b, &d);
			adj[a].push_back(P(b,d));
			adj[b].push_back(P(a,d));
		}
		Dijkstra(s);

		for (int i=0; i<t; i++) {
			int x; scanf("%d", &x);
			if (tracking(x))
				result.push_back(x);
		}
		sort(result.begin(), result.end());
		for (int i=0; i<result.size(); i++)
			printf("%d ", result[i]);
		puts("");
	}
	return 0;
}
