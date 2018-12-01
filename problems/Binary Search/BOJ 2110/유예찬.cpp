// baekjoon 2110 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 200000
typedef long long LL;
int N, C;
LL lo, hi, mid, rst, house[MAX_N];

bool gap(LL num) {
	int start = 0, cnt = 1;

	for (int i=1; i<N; i++)
		if (house[i] - house[start] >= num)
			start = i, cnt++;

	return cnt >= C;
}

int main() {
	scanf("%d %d", &N, &C);

	for(int i=0; i<N; i++) scanf("%lld", &house[i]);

	sort(house, house+N);

	lo=1; hi=house[N-1]-house[0];

	while (lo <= hi) {
		mid = (lo + hi)/2;
		if(gap(mid)) {
			rst = max(rst, mid);
			lo = mid+1;
		}
		else hi = mid-1;
	}
	printf("%lld", rst);
	return 0;
}