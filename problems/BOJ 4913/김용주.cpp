//BOJ 4913 Odsn
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1000001
int L, U, x, y, p_cnt, s_cnt;
int square[MAX_N], prime[MAX_N];
bool isPrime[MAX_N];

int main(){
	fill(isPrime+2, isPrime+MAX_N, true);
	s_cnt = 1;
	for(int i = 2; i < MAX_N; i++){
		if(isPrime[i]){
			p_cnt++;
			if(i%4 == 1) s_cnt++;
			for(long long j = i*2; j < MAX_N; j += i)
				isPrime[j] = false;
		}
		prime[i] = p_cnt;
		square[i] = s_cnt;
	}

	while(1){
		scanf("%d %d", &L, &U);
		if(L == -1 &&  U == -1)
			break;
		if(U < 2){
			x = 0;
			y = 0;
		}
		else if(L < 2){
			x = prime[U];
			y = square[U];
		}
		else{
			x = prime[U] - prime[L-1];
			y = square[U] - square[L-1];
		}
		printf("%d %d %d %d\n", L, U, x, y);
	}

	return 0;
}