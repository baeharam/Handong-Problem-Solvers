#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, f, s, visit[101];
vector<int> adj[101];

int main() {
	scanf("%d %d %d %d", &n, &f, &s, &m);

	int x, y;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	queue<int> q;
	q.push(f);
	int cnt = 0;
	visit[f] = 1;

	while (!q.empty()) {
		int q_size = q.size();
		for (int j = 0; j < q_size; j++) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < adj[cur].size(); i++) {
				int check = adj[cur][i];

				if (visit[check] == 0) {
					q.push(check);
					visit[check] = cnt + 1;
				}
			}
		}
		cnt++;
	}
	cnt--;

	if (visit[s] == 0) printf("-1\n");
	else	printf("%d\n", visit[s]);

	return 0;
}