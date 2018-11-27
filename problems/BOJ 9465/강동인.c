#include <stdio.h>
#include <stdlib.h>

int **arr, **result;
int *sum;

void FindMax(int i, int n);

int main() {
    
    int T, n;
    
    scanf("%d", &T);
    arr = (int **)malloc(sizeof(int*) * T);
    result = (int **)malloc(sizeof(int*) * T);
    sum = (int *)malloc(sizeof(int) * T);
    
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        arr[i] = (int * )malloc(sizeof(int) * 2 * n);
        result[i] =(int * )malloc(sizeof(int) * 2 * n);
        
        for (int j = 0; j < 2 * n; j++) {
            scanf("%d", &arr[i][j]);
        }
        
        FindMax(i, n);
        printf("%d\n", sum[i]);
    }
}


void FindMax(int i, int n) {
    
    sum[i] = 0;
    
    for (int k = 0; k < n; k++) {
        int max = 0;
        int maxj = 0;
        
        for (int j = 0; j < 2 * n; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
                maxj = j;
            }
        }
        
        if (max == 0) {
            break;
        }
        
        if (maxj < n) {
            arr[i][maxj] = 0;
            
            if (maxj != 0 )
                arr[i][maxj-1] = 0;
            
            if (maxj != (n - 1))
                arr[i][maxj+1] = 0;
            
        
            arr[i][maxj + n] = 0;
        }
        
        else {
            arr[i][maxj] = 0;
            
            if (maxj != n)
                arr[i][maxj-1] = 0;
            
            if (maxj != 2*n - 1)
                arr[i][maxj+1] = 0;
            
            arr[i][maxj - n] = 0;
        }
        
        result[i][k] = max;
        sum[i] += result[i][k];
    }
    
    
}

