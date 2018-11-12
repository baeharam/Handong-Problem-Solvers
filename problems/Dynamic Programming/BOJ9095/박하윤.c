// 백준_9095
#include <stdio.h>

#define Max_N 11
int N[Max_N];

int main()
{
    int n = 0;
    int T = 0;
    int i = 0;
    scanf("%d", &T);

    N[1] = 1; 
    N[2] = 2;
    N[3] = 3;

    for(i = 4; i <= Max_N; i++)
        N[i] = N[i - 1] + N[i - 2] + N[i - 3]; // f(x) = f(x-1) + f(x-2) + f(x-3)

    for(i = 0; i < T; i++){
        scanf("%d", &n);
        printf("%d\n", N[n]);
    }
    return 0;
}