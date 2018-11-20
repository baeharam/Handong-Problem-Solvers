#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#pragma warning(disable : 4996)

int n = 0;
int arr[64][64];

int conquer(int size, int x, int y)
{
	bool same = true;
	for (int i = y; i < y + size; i++){
		if (!same) break;
		for (int j = x; j < x + size; j++) {
			if (arr[y][x] != arr[i][j]) {
				same = false;
				break;
			}
		}
	}
	
	if (same) {
		printf("%d", arr[y][x]);
		return 0;
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	conquer(n, 0, 0);
	system("pause");
	return 0;
}
