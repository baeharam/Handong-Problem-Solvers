#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int board[64][64];


// general case
void Qtree (int x, int y, int N) {
    
    // base case
    if (N == 1) {
        printf("%d", board[y][x]);
        return;
    }
    
    bool flag = true;
    
    for (int i = y; i < (y + N) ; i++) {
        if (!flag) {
            break;
        }
        for (int j = x; j < (x + N) ; j++) {
            if (board[y][x] != board[i][j]) {
                flag = false;
                break;
            }
        }
    }
    
    if (flag) {
        printf("%d", board[y][x]);
        return;
    }
    
    //int new_length = n/2;
    
    
    printf("(");
    Qtree(x, y, N/2);
    Qtree(x+N/2, y, N/2);
    Qtree(x, y+N/2, N/2);
    Qtree(x+N/2, y+N/2, N/2);
    printf(")");
    
}

int main() {
    
    int n;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d" , &board[i][j]);
        }
    }
    
    Qtree(0, 0, n);
    printf("\n");
    
    
}

