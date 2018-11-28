#include <cstdio>
using namespace std;

int Max(int a, int b){
    return a > b ? a : b; }

int main()
{
    int T, n;
    scanf("%d", &T);
    
    while(T--){
        scanf("%d", &n);

        int sti[2][100001], ker[2][100001];
        for(int i = 0; i < 2; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &sti[i][j]);

        ker[0][0] = sti[0][0] = 0;
        ker[1][1] = sti[1][1]; ker[0][1] = sti[0][1];

        for(int i = 2; i <= n; i++){
            ker[0][i] = Max(ker[1][i - 1], ker[1][i - 2]) + sti[0][i];
            ker[1][i] = Max(ker[0][i - 1], ker[0][i - 2]) + sti[1][i];
        }
        printf("%d\n", Max(ker[0][n], ker[1][n]));
    }
    return 0;
}