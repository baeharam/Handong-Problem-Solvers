// baekjoon 2098 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_INF = 987654321;

int N, W[16][16], dp[16][1<<16];

int ropeCycle(int here, int visited) {
	if (dp[here][visited] != -1) return dp[here][visited];

	if (visited == (1<<N)-1) {
		if (W[here][0] != 0) return W[here][0];
		return MAX_INF;
	}

	int ret = MAX_INF;
	for (int i=0; i<N; i++) {
		if (visited & (1<<i) || W[here][i] == 0) continue;
		ret = min(ret, ropeCycle(i, visited | (1<<i) ) + W[here][i]);
	}
	return dp[here][visited] = ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++) 
			scanf("%d", &W[i][j]);

	memset(dp, -1, sizeof(dp));
	printf("%d\n", ropeCycle(0, 1));
	return 0;
}