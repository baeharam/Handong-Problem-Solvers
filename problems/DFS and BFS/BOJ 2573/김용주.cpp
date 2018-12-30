//BOJ2573 Odsn
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, year;
int iceberg[300][300], visited[300][300];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair <int, int> > q;

void dfs(int x, int y){
	visited[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m)) continue;
		if(visited[nx][ny]) continue;
		if(!iceberg[nx][ny]) continue;
		dfs(nx, ny);
	}
	return;
}

int main(){
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			scanf("%d", &iceberg[i][j]);
			if(iceberg[i][j])
				q.push({i, j});
		}

	while(!q.empty()){
		int qSize = q.size();
		year++;

		//빙산 업데이트. 빙산의 크기만큼 반복문을 돌리고 빙산의 상하좌우 확인해서 0의 갯수만큼 줄임
		while(qSize--){
			int x = q.front().first;
			int y = q.front().second;
			visited[x][y] = 1;
			int cnt = 0;
			q.pop();
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				//행렬 범위 밖이면 노카운트
				if((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m)) continue;
				//이미 업데이트 된 값이면 노카운트
				if(visited[nx][ny]) continue;
				if(!iceberg[nx][ny]) cnt++;
			}
			iceberg[x][y] -= cnt;
			if(iceberg[x][y] <= 0)
				iceberg[x][y] = 0;
			else q.push({x, y});
		}

		//빙산을 업데이트 했는데 빙산이 없으면 0을 출력
		if(q.empty()) {
			year = 0;
			break;
		}
		memset(visited, 0, sizeof(visited));

		//빙산이 분리되어 있는지 DFS로 확인. DFS로 쭉 돌았는데도 visited가 0인 부분이 있고 빙산이 있으면 seperate가 2이상
		int seperate = 0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(iceberg[i][j] && !visited[i][j]){
					visited[i][j] = 1;
					dfs(i, j);
					seperate++;
				}

		if(seperate > 1) break;
	}

	printf("%d\n", year);
	return 0;
}