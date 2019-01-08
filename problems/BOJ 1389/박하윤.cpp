#include <cstdio>

int n, m, f[101][101];

int main()
{
    int min = 987654321, ans = 0;

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < n+1; j++){
            if(i == j) f[i][j] = 0;
            else f[i][j] = min;
        }

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        f[a][b] = f[b][a] = 1;
    }

    for(int k = 1; k < n+1; k++)
        for(int i = 1; i < n+1; i++)
            for(int j = 1; j < n+1; j++){
                if(f[i][j] > f[k][j] + f[i][k])
                    f[i][j] = f[j][i] = f[k][j] + f[i][k];
            }
    for(int i = 1; i < n+1; i++){
        int temp = 0;
        for(int j = 1; j < n+1; j++)
            temp += f[i][j];
        if(min > temp){
            min = temp;
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}