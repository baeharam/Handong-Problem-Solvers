#include <iostream>
#include <stdio.h>

int i, j, s, arr[64][64];

void quadtree(int x, int y, int size, bool check){
	for (i = y; i < y+size; i++){
		for (j = x; j < x+size; j++){
			if (arr[y][x] != arr[i][j]){
				check = false;
				break;
			}
		}
	}
	
	if (check == true) {
		printf("%d",arr[y][x]);
		return;
	}
	bool ch = true ;
	int hsize = size/2;
	printf("(");
	quadtree(x, y, hsize, ch);
	quadtree(x+hsize, y, hsize, ch);
	quadtree(x, y+hsize, hsize, ch);
	quadtree(x+hsize, y+hsize, hsize, ch);
	printf(")");
}

int main() {
	scanf("%d", &s);
	for (i = 0; i < s; i++){
		for(j = 0; j < s; j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	quadtree(0, 0, s, false);
}
