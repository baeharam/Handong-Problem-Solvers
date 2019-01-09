#include <stdio.h>
#include <memory.h>
#define INF 1<<30
using namespace std;

int N, M;
int arr[101][101];
int visited[101];
void dfs(int s, int cnt);

int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	int result;
	int cmp = INF;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++)
			visited[j] = INF;
		dfs(i, 1);
		int temp = 0;
		for (int j = 1; j <= N; j++)
			temp += visited[j];
		if (cmp > temp){
			cmp = temp;
			result = i;
		}
	}
	printf("%d\n", result);
	return 0;
}

void dfs(int s, int cnt){
	for (int i = 1; i <= N; i++){
		if (arr[s][i] && visited[i] > cnt){
			visited[i] = cnt;
			dfs(i, cnt + 1);
		}
	}
}