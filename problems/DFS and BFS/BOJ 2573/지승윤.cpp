#include<stdio.h>
#include<memory.h>
#include<queue>

using namespace std;

int N, M;
int arr[310][310];
int save[310][310];
int m[310][310];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


typedef struct pos {
	int y, x;
}POS;

queue<pair<POS, int>> q;

int year;
int ans;

void fill(int y, int x) {
	m[y][x] = 0;
	queue<pair<int, int>> fq;
	fq.push({ y,x });

	while (!fq.empty()) {
		pair<int, int> cur = fq.front();
		fq.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.first + dy[i], nx = cur.second + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (m[ny][nx]) {
				m[ny][nx] = 0;
				fq.push({ ny,nx });
			}
		}
	}
}

bool isOne() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (m[i][j])
				return false;
	return true;
}

bool findPart() {
	memcpy(m, arr, sizeof(arr));
	for (int i = 0; i<N; i++)
		for (int j = 0; j<M; j++)
			if (arr[i][j]) {
				fill(i, j);
				return isOne();
			}
	return true;
}

void bfs() {
	while (!q.empty()) {
		pair<POS, int> cur = q.front();
		if (cur.second > year) {
			year++;
			memcpy(arr, save, sizeof(arr));

			if (!findPart()) {
				ans = year;
				return;
			}
		}
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (cur.first.y + dy[i] < 0 || cur.first.y + dy[i] >= N || cur.first.x + dx[i] < 0 || cur.first.x + dx[i] >= M)
				continue;
			if (!arr[cur.first.y + dy[i]][cur.first.x + dx[i]]) {
				if (save[cur.first.y][cur.first.x] > 0)
					save[cur.first.y][cur.first.x]--;
			}
		}
		if (save[cur.first.y][cur.first.x]) {
			q.push({ { cur.first.y,cur.first.x },cur.second + 1 });
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j])
				q.push({ { i,j }, 0 });
		}
	memcpy(save, arr, sizeof(arr));
	bfs();
	printf("%d\n", ans);
}