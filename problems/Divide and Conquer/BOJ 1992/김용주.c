#include <stdio.h>
#include <stdlib.h>

char quad[64][64];

void quadTree(int x, int y, int n) {
	int check = checkQuad(x, y, n);
	int s = n / 2;

	if (check == -1) {
		printf("(");
		quadTree(x, y, s);
		quadTree(x + s, y, s);
		quadTree(x, y + s, s);
		quadTree(x + s, y + s, s);
		printf(")");
	}

	if (check == 1) printf("1");
	if (!check)		printf("0");
}

int checkQuad(int x, int y, int n) {
	char arr = quad[y][x];

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr != quad[i][j])	return -1;
		}
	}

	if (arr == '1')	return 1;
	else			return 0;
}

int main(void) {
	int n = 0;
	char ch = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%c", &ch);
		for (int j = 0; j < n; j++)
			scanf("%c", &quad[i][j]);
	}

	quadTree(0, 0, n);

	return 0;
}