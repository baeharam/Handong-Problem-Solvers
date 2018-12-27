#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, w[16][16], dp[16][1 << 16];
const int imp = 999999999;

int TSP(int v, int visited) {
	//이미 값이 있으면 바로 return
	if (dp[v][visited] != -1) return dp[v][visited];

	// 모든 마을을 방문하면 bit값이 다 1이 되니까 확인
	if (visited == (1 << n) - 1) {
		if (w[v][0] != 0) return w[v][0];
		// 마지막 마을에서 처음 마을로 갈 수 없으면 불가능한값 출력
		return imp;
	}

	int r = imp;
	for (int i = 0; i < n; i++) {
		// i번 마을을 이미 방문 or 갈 수 없는 경우
		if (visited & (1 << i) || w[v][i] == 0) continue;
		// 아직 방문 안했고 갈 수 있음.
		r = min(r, TSP(i, visited | (1 << i)) + w[v][i]);
	}
	return dp[v][visited] = r;

}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &w[i][j]);

	memset(dp, -1, sizeof(dp));
	printf("%d", TSP(0, 1));
	return 0;
}