#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

int n = 0;
int arr[64][64];

void conquer(int size, int x, int y)
{
	if (size == 1) {
		printf("%d", arr[y][x]);
		return;
	}

	bool same = true;
	for (int i = y; i < y + size; i++)
	{
		if (!same)
			break;
		for (int j = x; j < x + size; j++)
			if (arr[y][x] != arr[i][j]) {
				same = false;
				break;
			}
	}

	if (same) {
		printf("%d", arr[y][x]);
		return;
	}
	
	int div = size / 2;
	printf("(");
	conquer(div, x, y);
	conquer(div, x+div, y);
	conquer(div, x, y+div);
	conquer(div, x+div, y+div);

	printf(")");
}


int main(void) {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	conquer(n, 0, 0);
	printf("\n");
	system("pause");

	return 0;
}