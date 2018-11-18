#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 65

int N;
char data[MAX_N][MAX_N];

static inline int checkColor(int x, int y, int n) {
	char fcor = data[y][x];
	for (int i=y; i<y+n; i++)
		for (int j=x; j<x+n; j++)
			if (fcor != data[i][j])
				return -1;
	if (fcor == '1') 	return 1;
	else 				return 0;
}

static void quadTree(int x, int y, int n) {
	int c_flag = checkColor(x, y, n);
	if (c_flag == -1) {
		printf("(");
		quadTree(x, y, n/2);
		quadTree(x+n/2, y, n/2);
		quadTree(x, y+n/2, n/2);
		quadTree(x+n/2, y+n/2, n/2);
		printf(")");
	}
	else {
		printf("%d", c_flag);
	}
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf(" %c", &data[i][j]);
	quadTree(0, 0, N);
}