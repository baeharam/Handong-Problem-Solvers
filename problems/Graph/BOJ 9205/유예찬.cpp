// baekjoon yechan 9205
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define LIMIT_DIST 1000
#define MAX_N 103

typedef struct _TAG_POSITION{
	int x, y;
}__POS;

__POS node[MAX_N];

int T, N;
bool visit[MAX_N], connect[MAX_N][MAX_N];

static inline int getDistance(__POS p1, __POS p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

static inline bool CheckConnect(__POS p1, __POS p2) {
	return (getDistance(p1, p2) > LIMIT_DIST) ? false : true;
}

static void initConnect() {
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			connect[i][j] = CheckConnect(node[i], node[j]);
}

static void DFS(int s) {
	visit[s] = true;
	for (int i=0; i<N; i++)
		if (!visit[N-1] && !visit[i] && connect[s][i])
			DFS(i);
}

int main() {
	scanf("%d", &T);
	for (int i=0; i<T; i++) {
		scanf("%d", &N);	N+=2;
		fill(visit, visit+N, false);
		for (int j=0; j<N; j++)
			scanf("%d %d", &node[j].x, &node[j].y);
		initConnect();
		DFS(0);
		if (visit[N-1]) printf("happy\n");
		else 			printf("sad\n");
	}
	return 0;
}