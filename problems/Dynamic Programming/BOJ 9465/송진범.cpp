#include <iostream>
#include<cstdio>
using namespace std;
#pragma warning(disable : 4996)

int max(int a, int b) {
	return (a > b ? a : b);
}
int main() {

	int n, i, j, k;
	scanf("%d", &n);
	while (n-- > 0) {
		int p = 0;
		int origin[2][100001];
		int dp[2][100001];
		

		scanf("%d", &p);

		for (k = 0; k <= 2; k++) {
			for (j = 1; j <= p; j++) {
				scanf("%d", &origin[k][j]);
			}
		}

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = origin[0][1];
		dp[1][1] = origin[1][1];

		for (i = 2; i <= p; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + origin[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + origin[1][i];
		}

		printf("%d", max(dp[0][p], dp[1][p]));
	}
	return 0;
}
