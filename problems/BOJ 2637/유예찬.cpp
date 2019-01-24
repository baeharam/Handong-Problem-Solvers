// baekjoon 2637 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 101

int N, M, adj[MAX_N][MAX_N], comp[MAX_N][MAX_N], result[MAX_N];
bool visited[MAX_N];

void backtracking(int curr, int num) {
	for (int i=1; i<=N; i++) {
		if (adj[curr][i]) {
			if (!visited[i]) result[i] += num*adj[curr][i];
			else backtracking(i, num*adj[curr][i]);
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	int X, Y, K;
	for (int i=0; i<M; i++) {
		scanf("%d%d%d", &X, &Y, &K);
		adj[X][Y]=K;
		visited[X] = true;
	}

	backtracking(N, 1);
	for (int i=1; i<=N; i++)
		if (!visited[i])
			printf("%d %d\n", i, result[i]);
	return 0;
}