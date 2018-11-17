#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int x;
	int y;
}Coord;

Coord cod[103];
int visit[103];
int t;
int n;

int distance(Coord p1, Coord p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

bool CheckDist(Coord p1, Coord p2) {
	return (distance(p1, p2) > 1000) ? false : true;
}

// 어려워서 다른사람들 코드 보고 했습니다.
void dfs(int a) {
	for (int i = 0; i < n + 2; i++) {
		if (visit[i] == 0) {
			if (CheckDist(cod[a], cod[i])) {
				visit[i] = 1;
				dfs(i);
			}
		}
	}
}

int main(void) {

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		memset(visit, 0, sizeof(visit));

		for (int j = 0; j < n + 2; j++) 
			scanf("%d %d", &cod[j].x, &cod[j].y);

		dfs(0);

		if (visit[n + 1])
			printf("happy\n");
		else
			printf("sad\n");
	}
	
	return 0;

}