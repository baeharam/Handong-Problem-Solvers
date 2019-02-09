//BOJ2003 수들의 합2
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10001
typedef long long ll;
int N, A[MAX_N];
ll M, sum[MAX_N];

int main(){
	scanf("%d %lld", &N, &M);
	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	ll ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = i; j < N; j++){
			if(sum[i] > M) continue;
			sum[i] += A[j];
			if(sum[i] == M) ans++;
		}
	}

	printf("%d", ans);
	return 0;
}