// baekjoon 1389 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int main() {
	int N, M, dist[101][101];
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
			dist[i][j] = i==j ? 0 : INF;

	for (int i=0; i<M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		dist[a][b] = dist[b][a] = 1;
	}

	for (int k=1; k<=N; k++)
		for (int i=1; i<=N; i++)
			for (int j=1; j<=N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

	int minIdx=0, minValue=INF;
	for (int i=1; i<=N; i++){
		int tmp = 0;
		for (int j=1; j<=N; j++)
			tmp += dist[i][j];
		if (minValue > tmp) {
			minIdx=i;
			minValue=tmp;
		}
	}
	printf("%d\n", minIdx);
}