//BOJ5676
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//10^5의 크기보다 커야함
const int SIZE = 1<<4;
int sequence[2*SIZE], a;

void update(int i, int val){
	i += SIZE;
	if(val > 0) val = 1;
	else if (val < 0) val = -1;
	sequence[i] = val;
//	printf("val: %d", sequence[i]);
	while(i > 1){
		i /= 2;
		sequence[i] = sequence[i*2] * sequence[i*2+1];
	}
}

int mul(int L, int R, int node, int nodeL, int nodeR){
	if(nodeR < L || nodeL > R) return 1;
	if(L <= nodeL && R >= nodeR) return sequence[node];
	int mid = (nodeL + nodeR)/2;
	return mul(L, R, node*2, nodeL, mid) * mul(L, R, node*2+1, mid+1, nodeR);
}

int main(){
	int N, K;
	while(scanf("%d %d", &N, &K) != -1){
		fill(sequence, sequence+SIZE*2, 1);
		for(int i = 1; i <= N; i++){
			scanf("%d", &a);
			update(i, a);
		}
		char ch;
		int L, R;
		for(int i = 1; i <= K; i++){
			scanf(" %c %d %d", &ch, &L, &R);
			if(ch == 'C') {
				update(L, R);
			}
			if(ch == 'P'){
				int ans = mul(L, R, 1, 0, SIZE-1);
				  // printf("ans: %d\n", ans);
				if(ans > 0) printf("+");
				else if(ans < 0) printf("-");
				else printf("0");
			}
			// for(int j = 0; j < SIZE*2; j++)
			// 	printf("%d: %-5d",j, sequence[j]);
			// printf("\n");

		}
		printf("\n");
	}

	return 0;
}