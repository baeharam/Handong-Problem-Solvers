#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, A, B, dist[101][101];
	scanf("%d %d", &N, &M);

	for(int i = 0; i <= N; i++)
		for(int j = 0; j <= N; j++)
			dist[i][j] = 1000;

	for(int i = 1; i <= M; i++){
		scanf("%d %d", &A, &B);
		dist[A][B] = 1;
		dist[B][A] = 1;
	}

	//플루이드 와샬 알고리즘
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(i!=j)	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 				//printf("%-5d ", dist[i][j]);
			}
			//printf("\n");
		}
			//printf("\n");
	}	

	int ans = 0;
	int maxi = 1000;
	for(int i = 1; i <= N; i++){
		int sum = 0;
		for(int j = 1; j <= N; j++){
			if(i != j) sum += dist[i][j];
		}
		if(maxi > sum){
			maxi = sum;
			ans = i;
		}
	}

	printf("%d", ans);
	int result = 0;

	return 0;
}
