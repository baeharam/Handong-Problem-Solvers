#include <stdio.h>
#include <string.h>
#include "hpp.h"

#define MAX(a,b) (a > b? a : b)

int main(){
    int arr[1][1000000];
    int i, j, w, max;
    arr[0][0] = 0;
    arr[1][0] = 0;
    
    scanf("%d", &w);
    for(i=0; i<2; i++){
        for(j=1; j<w+1; j++)
            scanf("%d", &arr[i][j]);
    }
    
    for(j=2; j<w+1; j++){
        arr[0][j] = MAX(arr[1][j-1], arr[1][j-2]) + arr[0][j];
        arr[1][j] = MAX(arr[0][j-1], arr[0][j-2]) + arr[1][j];
    }
    
    max = MAX(arr[0][j], arr[1][j]);
    printf("max number: %d", max);
    return 0;
}
