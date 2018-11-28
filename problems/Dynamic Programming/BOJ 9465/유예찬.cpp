// baekjoon 9465 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_N 100001
int T, n, result, price[2][MAX_N], dp[MAX_N][3];

// pos : 0 왼쪽 안띰, 1 왼쪽 상단 스티커 띤 상태, 2 왼쪽 하단 스티커 띤 상태
int sticker(int x, int pos){
	if (x == n) return 0;
	if (~dp[x][pos]) return dp[x][pos];

	int tmp = sticker(x+1, 0);
	if (pos != 1)	tmp = max(tmp, sticker(x+1, 1) + price[0][x]);
	if (pos != 2)	tmp = max(tmp, sticker(x+1, 2) + price[1][x]);

	dp[x][pos] = tmp;

	return tmp;
}

int main(){
	int top_on = 0; // Choose TOP DOWN / BOTTOM UP

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		for (int i=0; i<2; i++)
			for (int j=0; j<n; j++)
				scanf("%d", &price[i][j]);

		memset(dp, -1, sizeof(dp));

		if (top_on) {
			result = sticker(0,0); 	// TOP DOWN
		}
		else {
			dp[0][0] = 0;
			dp[0][1] = price[0][0];
			dp[0][2] = price[1][0];

			for (int i=1; i<n; i++) { 		// BOTTOM UP
				dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
				dp[i][1] = max(dp[i-1][0], dp[i-1][2])+price[0][i];
				dp[i][2] = max(dp[i-1][0], dp[i-1][1])+price[1][i];
			}
			result = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
		}
		printf("%d\n", result);
	}
}