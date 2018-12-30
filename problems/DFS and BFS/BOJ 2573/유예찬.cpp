// baekjoon 2573 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 300
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int N, M, meltnum, iceberg[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
queue<int> ice;

inline bool checkrange(int x, int y, int n, int m) {
	return ((x < 0) || (x >= n) || (y < 0) || (y >= m));
}

int dfs(int x, int y) {
	int ret = 1;
	visited[x][y]=true;
	for (int d=0; d<4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (checkrange(nx, ny, N, M)) continue;
		if (!iceberg[nx][ny]) continue;
		if (visited[nx][ny]) continue;
		ret += dfs(nx, ny);
	}
	return ret;
}

int bfs() {
	int depth = 0, result=-1;
	while (ice.size()) {
		int iceSize = ice.size();
		memset(visited, 0,sizeof(visited));
		while (iceSize--) {
			int cx = ice.front()/M, cy = ice.front()%M; ice.pop();
			int cnt = 0;
			visited[cx][cy]=true;
			for (int d=0; d<4; d++) {
				int nx =cx+dx[d], ny=cy+dy[d];
				if (checkrange(nx, ny, N, M)) continue;
				if (visited[nx][ny]) continue;
				if (!iceberg[nx][ny]) cnt++;
			}
			iceberg[cx][cy] = max(iceberg[cx][cy]-cnt, 0);
			if (!iceberg[cx][cy]) meltnum++;
			else ice.push(cx*M+cy);
		}
		if (ice.empty()) return 0;
		depth++;
		memset(visited, 0, sizeof(visited));
		if (meltnum + dfs(ice.front()/M, ice.front()%M) != N*M) return depth;
	}
	return result;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++){
		for (int j=0; j<M; j++){
			scanf("%d", &iceberg[i][j]);
			if (!iceberg[i][j]) meltnum++;
			else ice.push(i*M+j);
		}
	}
	printf("%d\n", bfs());
	return 0;
}