//1992
#include <cstdio>
using namespace std;

int N, a[64][64];   

void quadtree(int size, int x, int y){
    int b = a[y][x];
    bool flag = true;

    for(int i = y; i < y + size; i++)
        for (int j = x; j < x + size; j++) {
            if (b != a[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%d", b);
            return;
        }
        else{
            printf("(");
            quadtree(size/2, x, y);
            quadtree(size/2, x + size/2, y);
            quadtree(size/2, x, y + size/2);
            quadtree(size/2, x + size/2, y + size/2);
            printf(")");
        }
}  
int main(){
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%1d", &a[i][j]);
    
    quadtree(N, 0, 0);
    printf("\n");
}