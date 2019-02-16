#include <cstdio>
#include <stdlib.h>
int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n = 9;
int square(int x, int y) {
	return (x/3)*3 + (y/3);
}
void go(int z) {
	if(z == 81) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int x = z/n;
	int y = z%n;
	if(a[x][y] != 0) {
		go(z+1);
	}
	else {
		for(int i=1; i<=9; i++) {
			if(c[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i]==0) {
				c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
				a[x][y] = i;
				go(z+1);
				c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
				a[x][y] = 0;

			}
		}
	}
}
int main() {
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++){
			scanf("%d",&a[i][j]);
			if(a[i][j] != 0) {
				c[i][a[i][j]] = true;
				c2[j][a[i][j]] = true;
				c3[square(i,j)][a[i][j]] = true;
			}
		}
		go(0);
}