// bakejoon 1600 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N = 200;
const int MAX_K = 30;
const int house_dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
const int common_dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Pos{
	int x, y, k;
	Pos(){}
	Pos(int x, int y, int k):x(x), y(y), k(k){}
};

int N, M, K, board[MAX_N][MAX_N];
bool visited[MAX_K][MAX_N][MAX_N];

inline bool CheckMonkey(int x, int y, int k) {
	if (x < 0 || x >= N || y < 0 || y >= M || visited[k][x][y] || board[x][y]) return true;
	return false;
}

int BFS() {
	queue<Pos> q;

	q.push(Pos(0, 0, K));
	visited[K][0][0]=true;

	int depth = 0;
	while (!q.empty()) {
		int qSize = q.size();
		while (qSize--) {
			int curr_x = q.front().x;
			int curr_y = q.front().y;
			int curr_k = q.front().k;
			q.pop();

			if (curr_x == N-1 && curr_y == M-1) return depth;

			if (curr_k) {
				for (int d=0; d<8; d++) {
					int nx = curr_x + house_dir[d][0];
					int ny = curr_y + house_dir[d][1];
					int nk = curr_k - 1;
					if (CheckMonkey(nx, ny, nk)) continue;

					visited[nk][nx][ny] = true;
					q.push(Pos(nx, ny, nk));
				}
			}
			for (int d=0; d<4; d++) {
				int nx = curr_x + common_dir[d][0];
				int ny = curr_y + common_dir[d][1];
				if (CheckMonkey(nx, ny, curr_k)) continue;

				visited[curr_k][nx][ny] = true;
				q.push(Pos(nx, ny, curr_k));
			}
		}
		depth++;
	}
	return -1;
}

int main() {
	scanf("%d%d%d", &K, &M, &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<M; j++)
			scanf("%d", &board[i][j]);

	printf("%d\n", BFS());
	return 0;
}