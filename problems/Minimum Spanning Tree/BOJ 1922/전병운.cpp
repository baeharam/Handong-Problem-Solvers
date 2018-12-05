#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1001], ans, n, m;
class Edge {
public:
    int x, y, cost;
    Edge() {
        x = y = cost = -1;
    }
    Edge(int x, int y, int cost) {
        this->x = x;
        this->y = y;
        this->cost = cost;
    }
    bool operator < (Edge &other){
        return cost < other.cost;
    }
};
int find(int x){
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y, int cost){
    x = find(x);
    y = find(y);
    if (x == y) return;
    parent[x] = y;
    ans += cost;
}
vector <Edge> a;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++) {
        int x = 0, y = 0, cost = 0;
        cin >> x >> y >> cost;
        a.push_back(Edge(x, y, cost));
    }
    sort(a.begin(), a.end());
    for (auto i : a)
        merge(i.x, i.y, i.cost);
    cout << ans << endl;
}
