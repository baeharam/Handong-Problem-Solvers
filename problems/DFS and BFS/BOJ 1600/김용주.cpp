//BOJ1600
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX_H 201
#define MAX_K 32
struct M{
	int x, y, c;
};
int k, w, h, board[MAX_H][MAX_H];
bool visit[MAX_H][MAX_H][MAX_K];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int ox[4] = {0, 1, 0, -1};
int oy[4] = {1, 0, -1, 0};

int bfs(int sx, int sy){
	queue<M> q;
	q.push({sx, sy, k});
	visit[sy][sx][k] = true;
	int depth = 0;
	while(!q.empty()){
		int qSize = q.size();
		for(int i = 0; i < qSize; i++){
			int curx = q.front().x;
			int cury = q.front().y;
			int cnt = q.front().c;
			q.pop();
			if(curx == w-1 && cury == h-1) return depth;
			if(cnt > 0){
				for(int j = 0; j < 8; j++){
					int nx = curx + dx[j];
					int ny = cury + dy[j];
					if((nx < 0 || ny < 0) || (nx >= w || ny >= h)) continue;
					if(board[ny][nx] == 1) continue;
					if(visit[ny][nx][cnt-1]) continue;
					q.push({nx, ny, cnt-1});
					visit[ny][nx][cnt-1] = true;
				}
			}
			for(int j = 0; j < 4; j++){
				int nx = curx + ox[j];
				int ny = cury + oy[j];
				if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
				if(board[ny][nx] == 1) continue;
				if(visit[ny][nx][cnt]) continue;
				q.push({nx, ny, cnt});
				visit[ny][nx][cnt] = true;
			}
		}
		depth++;
	}
	return -1;
}

int main(){
	scanf("%d %d %d", &k, &w, &h);
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			scanf("%d", &board[i][j]);
		}
	}
	printf("%d", bfs(0, 0));

	return 0;
}