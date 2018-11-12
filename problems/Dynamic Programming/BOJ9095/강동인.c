#include <stdio.h>

int main() {
    int space[11];
    int n;
    int input[11];
    
    space[0] = 1;
    space[1] = 2;
    space[2] = 4;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);
    
    for (int i = 3; i < 11 ; i++)
        space[i] = space[i-1] + space[i-2] + space[i-3];
    
    for (int i = 0; i < n; i++)
        printf("%d\n", space[input[i]-1]);
    
    return 0;
}
