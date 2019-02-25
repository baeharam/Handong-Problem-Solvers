// baekjoon 1256 yechan
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M, K, c[222][111];

int comb(int n, int r) {
	if (n < 0 || r < 0 || n < r) return 0;
	if (c[n][r]) return c[n][r];
	if (n == 0 || r == 0 || n == r) return c[n][r] = 1;
	return c[n][r] = min(comb(n-1, r-1) + comb(n-1, r), (int)1e9);
}

void tracking(int n, int m, int k, int pos) {
	if (N+M == pos) return;
	int cnt = comb(n+m-1,m);
	if (k > cnt){
		printf("z");
		tracking(n,m-1,k-cnt, pos+1);
	}
	else {
		printf("a");
		tracking(n-1, m, k, pos+1);
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	if (K > comb(N+M,N)) puts("-1");
	else tracking(N, M, K, 0);
	return 0;
}