//BOJ1837 암호제작
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_K 1000001
typedef long long ll;
bool isPrime[MAX_K];

int main(){
	char P[101];
	int K;
	scanf("%s %d", &P, &K);

	for(int i = 2; i < K; i++){
		if(isPrime[i]) continue;
		for(int j = i+i; j < K; j += i)
			isPrime[j] = true;
	}

	for(int i = 2; i < K; i++){
		if(!isPrime[i]){
			int p_min = 0;
			for(int j = 0; j < strlen(P); j++){
				p_min = (p_min * 10 + (P[j] - '0')) % i;
			}
			if(p_min == 0){
				printf("BAD %d", i);
				return 0;
			}
		}
	}
	printf("GOOD");
	return 0;
}