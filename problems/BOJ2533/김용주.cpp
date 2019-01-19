#include <cstdio>
#include <vector>
using namespace std;
#define MAX_N 1000001
int N, dp[MAX_N][2], a, b;
vector<int> edge[MAX_N], child[MAX_N];
bool visit[MAX_N];

//tree 형성
void dfs(int cur){
	visit[cur] = true;
/*	for(int i = 0; i < edge[cur].size(); i++)
		int next = edge[cur][i];
		밑에있는 코드와 같은 의미
*/
	for(int next: edge[cur]){
		if(!visit[next]){
			child[cur].push_back(next);
			dfs(next);
		}
	}
}

int earlyAdopter(int cur, bool check){
	if(dp[cur][check]) return dp[cur][check];
	printf("%d\n", cur);
	int cnt = 0;
	//얼리어답터일 경우
	if(check){
		for(int next: child[cur])
			cnt += min(earlyAdopter(next, false), earlyAdopter(next, true));
		dp[cur][check] = cnt + 1;
	}
	//얼리어답터가 아닌 경우
	else{
		for(int next: child[cur])
			cnt += earlyAdopter(next,true);
		dp[cur][check] = cnt;
	}
	return dp[cur][check];
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i < N; i++){
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1);
	int ans = min(earlyAdopter(1, false),earlyAdopter(1, true));
	printf("%d\n", ans);
	return 0;
}