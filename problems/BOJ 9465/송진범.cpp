#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
int main() {

	int N = 0;
	cin >> N;
	for (int n = 0; N > 0; N--)
	{
		int P = 0;
		int origin[2][100001];
		int dp[2][100001];
		cin >> P;

		for (int i = 0; i < P; i++)
		{
			cin >> origin[0][i];
		}
		for (int i = 0; i < P; i++)
		{
			cin >> origin[1][i];
		}

		dp[0][0] = 0;
		dp[1][0] = 0;
		dp[0][1] = origin[0][1];
		dp[1][1] = origin[1][1];

		for (int i = 2; i <= P; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + origin[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + origin[1][i];
		}

		printf("%d", max(dp[0][P], dp[1][P]));

		system("pause");
	}
	return 0;
}