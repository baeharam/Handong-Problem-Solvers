// baekjoon 2698 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_T=1001;
const int MAX_N=101;
typedef long long ll;

int T, N, K;
ll dp[MAX_N][MAX_N][2];

ll tracking(int n, int k, int state) {
	if (k < 0) return 0;
	ll &ret=dp[n][k][state];
	if (ret!=-1) return ret;
	if (n==0 && k==0) return 1;
	if (n==0) return 0;
	ret=0;
	ret+=tracking(n-1, k, 0); // pos n, write 0
	ret+=tracking(n-1, (state)?k-1:k, 1); // pos n, write 1
	return ret;
}

int main() {
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	while (T--) {
		scanf("%d%d",&N,&K);
		printf("%lld\n", tracking(N, K, 0));
	}
	return 0;
}