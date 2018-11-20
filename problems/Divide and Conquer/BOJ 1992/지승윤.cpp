#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
​
int n;
int a[64][64];
​
void solve(int size, int x, int y) {
    if (size == 1) {
        printf("%d", a[y][x]);
        return;
    }
​
    bool same = true;
    for (int i = y; i < y + size; i++) {
        if (!same) break;
        for (int j = x; j < x + size; j++) {
            if (a[y][x] != a[i][j]) {
                same = false;
                break;
            }
        }
    }
​
    if (same) {
        printf("%d", a[y][x]);
        return;
    }
​
    int ns = size / 2;
  
    printf("(");
    solve(ns, x, y);
    solve(ns, x + ns, y);
    solve(ns, x, y + ns);
    solve(ns, x + ns, y + ns);
    printf(")");
}
​
int main(void) {
    scanf("%d", &n);
​
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
​
    solve(n, 0, 0);
    printf("\n");
​
    return 0;
}