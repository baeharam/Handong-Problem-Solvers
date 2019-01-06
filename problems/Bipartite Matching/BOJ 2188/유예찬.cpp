// baekjoon 2188 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 201

int N, M, x, y, cnt;
vector<int> adj[MAX_N];
int A[MAX_N], B[MAX_N];
bool visited[MAX_N];

bool dfs(int a) {
	visited[a] = true;
	for (int b: adj[a]) {
		if (!B[b] || (!visited[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++) {
		scanf("%d", &x);
		while (x--){
			scanf("%d", &y);
			adj[i].push_back(y);
		}
	}

	for (int i=1; i<=N; i++) {
		fill(visited, visited+MAX_N, false);
		if (dfs(i)) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
