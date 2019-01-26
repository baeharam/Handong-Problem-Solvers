#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct edge {
    int num, val;
};

int blocks[101][101];
int in[101];
int n, m, x, y, k;

int main() {
    scanf("%d %d", &n, &m);
    vector<vector<edge>> vec(n+1);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &k);
        vec[y].push_back({ x,k });
        in[x]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            q.push(i);
            blocks[i][i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next : vec[cur]) {
            for (int i = 1; i <= n; ++i)
                blocks[next.num][i] += blocks[cur][i] * next.val;

            in[next.num]--;
            if (!in[next.num])
                q.push(next.num);
        }
    }

    for (int i = 1; i <= n; ++i)
        if (blocks[n][i])
            printf("%d %d\n", i, blocks[n][i]);

    return 0;
}
