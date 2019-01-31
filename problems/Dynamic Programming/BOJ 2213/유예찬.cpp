// baekjoon 2213 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 10001

int N;
int weight[MAX_N], dp[MAX_N][2];
int visited[MAX_N];
vector<int> adj[MAX_N];
vector<int> st;

// state:0 (X), 1 (include)
int dfs(int root, int state) {
	if (dp[root][state]) return dp[root][state];

	visited[root]=1;
	int ret = (state) ? weight[root] : 0;
	for (int i=0; i<adj[root].size(); i++) {
		int next = adj[root][i], tmp = 0;
		if (!visited[next]) {
			tmp = dfs(next, 0);
			if (!state) tmp = max(tmp, dfs(next, 1));
		}
		ret += tmp;
	}
	visited[root]=0;

	dp[root][state] = ret;
	return dp[root][state];
}

void backtracking(int root, int state) {
	if (!dp[root][state]) return;

	visited[root]=1;
	if (state) st.push_back(root);

	for (int i=0; i<adj[root].size(); i++) {
		int next = adj[root][i], tmp = 0;
		if (!visited[next]) {
			if (state) backtracking(next, 0);
			else backtracking(next, (dp[next][0] > dp[next][1]) ? 0 : 1);
		}
	}
	visited[root]=0;
}

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &weight[i]);

	for (int i=1; i<N; i++) {
		int u, v; scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ret = max(dfs(1,0), dfs(1,1));
	printf("%d\n", max(dfs(1,0), dfs(1,1)));
	int state = (dp[1][0] > dp[1][1]) ? 0 : 1;
	backtracking(1, state);
	sort(st.begin(), st.end());
	for (int i=0; i<st.size(); i++) {
		printf("%d ", st[i]);
	}
	return 0;
}