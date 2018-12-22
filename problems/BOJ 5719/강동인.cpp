#include<iostream>
#include<vector>
#include<functional>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;

#define INF 99999999
#define MAX_SIZE 500

vector<P> vt[MAX_SIZE];
vector<int> reverse_edge[MAX_SIZE];

priority_queue<P, vector<P>, greater<P>> pq;

int dist[MAX_SIZE];
int n, m, s, d, u, v, p;

void delete_edge(int dest) {

	if (dest == s) return;

		for (int i = 0; i < reverse_edge[dest].size(); i++) {
			for (int j = 0; j < vt[reverse_edge[dest][i]].size(); j++) {
				if (vt[reverse_edge[dest][i]][j].second == dest) {

					vt[reverse_edge[dest][i]][j].first = INF;
					delete_edge(reverse_edge[dest][i]);
				}
			}
		}
}

void dikstra(int start) {

	dist[start] = 0;
	pq.push(P(dist[start], start));

	while (!pq.empty()) {

		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < vt[now].size(); i++) {

			int next_c = vt[now][i].first;
			int next_v = vt[now][i].second;

			if (dist[next_v] >= dist[now] + next_c) {

				if (dist[next_v] > dist[now] + next_c) {

					reverse_edge[next_v].clear();
				}

				dist[next_v] = dist[now] + next_c;
				reverse_edge[next_v].push_back(now);
				pq.push(P(dist[next_v], next_v));
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	while (1) {

		cin >> n >> m;

		if (n == 0 && m == 0) break;

		cin >> s >> d;

		for (int i = 0; i < n; i++) {
			dist[i] = INF;
			vt[i].clear();
			reverse_edge[i].clear();
		}

		for (int i = 0; i < m; i++) {

			cin >> u >> v >> p;
			vt[u].push_back(P(p, v));
		}

		dikstra(s);

		if (dist[d] == -1) {
			cout << -1 << '\n';
		}

		else {

			delete_edge(d);

				for (int i = 0; i < n; i++) {
					dist[i] = INF;
				}

				dikstra(s);

				if (dist[d] == INF) {
					cout << -1 << '\n';
				}

				else {
					cout << dist[d] << '\n';
				}
		}
	}
	return 0;
}
