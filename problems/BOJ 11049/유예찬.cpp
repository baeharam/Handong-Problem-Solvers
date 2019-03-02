// baekjoon 11049 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=501;
const int MAX_INF=1e9;
int N, r, c, matrix[MAX_N][2], dp[MAX_N][MAX_N];

int backtracking(int l, int r) {
	if (l==r) return 0;
	int &ret=dp[l][r];
	if (ret) return ret;
	ret=MAX_INF;
	for (int k=l; k<r; k++)
		ret=min(ret, backtracking(l,k)+backtracking(k+1,r)+matrix[l][0]*matrix[k][1]*matrix[r][1]);
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d %d", &matrix[i][0], &matrix[i][1]);
	printf("%d\n", backtracking(0, N-1));
	return 0;
}