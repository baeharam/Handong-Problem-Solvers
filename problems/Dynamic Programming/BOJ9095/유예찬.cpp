// baekjoon 9095 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 11
int T, n, minDP[MAX_N];

int main()
{
	scanf("%d", &T);

	minDP[3] = 4; minDP[2] = 2; minDP[1] = 1;

	for ( int i = 4; i < 11; i++ )
		minDP[i] = minDP[i-1] + minDP[i-2] + minDP[i-3];

	for( int i = 0; i < T; i++ )
		scanf("%d", &n), printf("%d\n", minDP[n]);
	return 0;
}

