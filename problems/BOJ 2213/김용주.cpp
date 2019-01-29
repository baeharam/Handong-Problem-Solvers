//BOJ2213 트리의 독립집합
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 10001
int n, node[MAX_N], a, b, dp[MAX_N][2];
bool visit[MAX_N];
vector<int> edge[MAX_N], result;

void dfs(int cur, int pre){
	visit[cur] = true;
	dp[cur][1] = node[cur];
	for(int next: edge[cur]){
		if(cur == pre) continue;
		if(!visit[next]){
			dfs(next, cur);
			dp[cur][1] += dp[next][0];
			dp[cur][0] += max(dp[next][0], dp[next][1]);
		}
	}
}

void idSet(int cur, int pre, bool state){
	if(state){
		result.push_back(cur);
		for(int next: edge[cur]){
			if(next == pre) continue;
			idSet(next, cur, 0);
		}
	}
	else {
		for(int next: edge[cur]){
			if(next == pre) continue;
			if(dp[next][0] < dp[next][1]) idSet(next, cur, 1);
			else idSet(next, cur, 0);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &node[i]);
	while(scanf("%d %d", &a, &b) != EOF){
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1, 0);
	if(dp[1][0] < dp[1][1]) idSet(1, 0, 1);
	else idSet(1, 0, 0);
	sort(result.begin(), result.end());
	printf("%d\n", max(dp[1][0], dp[1][1]));
	for(int i = 0; i < result.size(); i++)
		printf("%d ", result[i]);

	return 0;
}