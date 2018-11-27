#include <iostream>
#include <stdio.h>

int Max(int a, int b){
	return (a > b ? a : b);
}

int main() {
	int tcase, n, i, j;
	scanf("%d", &tcase);
	while(tcase-- > 0){
		int arr1[2][100001], arr2[2][100001];
		scanf("%d", &n);
		for(i = 0; i <= 1; i++){
			for(j = 1; j <= n; j++){
				scanf("%d", &arr2[i][j]);
			}
		}
		arr1[0][0] = arr1[1][0] = 0;
		arr1[0][1] = arr2[0][1];
		arr1[1][1] = arr2[1][1];
		for(i = 2; i <= n; i++){
			arr1[0][i] = Max(arr1[1][i - 1], arr1[1][i - 2]) + arr2[0][i];
			arr1[1][i] = Max(arr1[0][i - 1], arr1[0][i - 2]) + arr2[1][i];
		}
		printf("%d\n", Max(arr1[0][n], arr1[1][n]));
	}
}
