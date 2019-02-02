#include<cstdio>
#include<algorithm>
#define x first
#define y second
using namespace std;

typedef pair<int, int> point;
point p[100000], low[100000], up[100000];

int n, sl, su;
long long ccw(point i, point j, point k) {
    return 1LL * (j.x - i.x)*(k.y - i.y) - 1LL * (k.x - i.x)*(j.y - i.y);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d %d", &p[i].x, &p[i].y);
    sort(p, p + n);
    for (int i = 0; i < n; i++) {
        while (sl > 1 && ccw(low[sl - 2], low[sl - 1], p[i]) >= 0) sl--;
        while (su > 1 && ccw(up[su - 2], up[su - 1], p[i]) <= 0) su--;
        low[sl++] = up[su++] = p[i];
    }
    printf("%d", sl + su - 2);
    return 0;
}