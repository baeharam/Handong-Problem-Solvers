// baekjoon 4913 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 1000001LL
typedef long long ll; 
int L, U, x, y, cnt, square_cnt;
int localSum[MAX_N], squareSum[MAX_N];
bool prime[MAX_N];

int main() {
	prime[1]=true;
	square_cnt++;
	for (ll i=2; i<MAX_N; i++) {
		if (!prime[i]){
			++cnt;
			if (i%4 == 1) ++square_cnt;
			for (ll j=i*i; j<MAX_N; j+=i) {
				prime[j] = true;
			}
		}
		localSum[i]=cnt;
		squareSum[i]=square_cnt;
	}
	while (1) {
		scanf("%d %d", &L, &U);
		if (L==-1 && U==-1) break;
		printf("%d %d ", L, U);
		L = max(L, 1); U=max(U, 1);
		printf("%d ", localSum[U]-localSum[L-1]);
		printf("%d\n", squareSum[U]-squareSum[L-1]);
	}
	return 0;
}