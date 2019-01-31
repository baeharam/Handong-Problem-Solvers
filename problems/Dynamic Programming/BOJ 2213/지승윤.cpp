#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> MIS[10001][2];
int N, a, b;
int maxx[10001][2], w[10001];
void dfs(int cur, int par) {
	MIS[cur][1].push_back(cur);
	maxx[cur][1] = w[cur];
	for (auto next : adj[cur]) {
		if (next == par) continue;
		dfs(next, cur);
		maxx[cur][1] += maxx[next][0];
		for (auto i : MIS[next][0]) {
			MIS[cur][1].push_back(i);
		}
		maxx[cur][0] += max(maxx[next][0], maxx[next][1]);
		int tmp = (maxx[next][0] < maxx[next][1] ? 1 : 0);
		for (auto i : MIS[next][tmp]) {
			MIS[cur][0].push_back(i);
		}
	}
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> w[i];
	}
	adj.resize(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	cout << max(maxx[1][0], maxx[1][1]) << '\n';
	int tmp = (maxx[1][0] < maxx[1][1] ? 1 : 0);
	
	sort(MIS[1][tmp].begin(), MIS[1][tmp].end());
	for (auto i : MIS[1][tmp]) {
		cout << i << ' ';
	}	
}
