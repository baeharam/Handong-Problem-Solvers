#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, a, b, c, i, cnt, sum;
 
struct edge {
    int cost, from, to;
};
bool operator<(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}
edge E[1000001];
 
int parent[100001];
 
int find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}
 
void merge(int x, int y) {
    x = parent[x];
    y = parent[y];
    parent[x] = y;
}
 
int main() {
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        E[i] = { c,a,b };
    }
    for (i = 1; i <= n; ++i)
        parent[i] = i;
    sort(E, E + m);
 
    i = 0;
    while (cnt != n - 2) {
        a = E[i].from;
        b = E[i].to;
        if (find(a) != find(b)) {
            merge(a, b);
            cnt++;
            sum += E[i].cost;
        }
        i++;
    }
    printf("%d", sum);
    return 0;
}