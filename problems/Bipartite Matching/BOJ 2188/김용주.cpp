//BOJ2188 Odsn
#include <cstdio>
#include <vector>
using namespace std;
#define MAX_N 202

int N, M, A[MAX_N], B[MAX_N], Si, K;
vector<int> adj[MAX_N];
bool visited[MAX_N];

//A와 B를 매칭
bool dfs(int a){
	visited[a] = true;
	for(int i = 0; i < adj[a].size(); i++){
		int b = adj[a][i];
		//반대편 매칭 X or 매칭되어 있어도 다른 정점과 매칭이 가능할 경우
 		if(!B[b]|| (!visited[B[b]] && dfs(B[b]))){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++){
		scanf("%d", &Si);
		for(int j = 1; j <= Si; j++){
			scanf("%d", &K);
			adj[i].push_back(K);
		}
	}

	int ans = 0;
	for(int i = 1; i <= N; i++){
		if(!A[i])  {
			fill(visited, visited+N, false);
			if(dfs(i)) ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}