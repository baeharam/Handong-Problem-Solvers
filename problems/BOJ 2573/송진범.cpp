#include <iostream>
#include <queue>
using namespace std;
int a[301][301],d[301][301], c[301][301], dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
int n, m, score,cnt,t;
void melt(int i, int j)
    score = 0;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (1 <= x && x <= n && 1 <= y &&y <= m && a[x][y] == 0 && d[x][y]==0) { score++; }
    }
    if (a[i][j] - score < 0) { a[i][j] = 0; }
    else
    {
        a[i][j] -= score;
    }
    d[i][j] = 1;
}

void BFS(int i, int j, int cnt)
{
    queue <pair<int, int>> q;
    q.push(make_pair(i, j));
    c[i][j] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (1 <= nx && nx <= n && 1 <= ny && ny <= m)
            {
                if (c[nx][ny] == 0 && a[nx][ny] > 0)
                {
                    q.push(make_pair(nx, ny));
                    c[nx][ny] = 1;
                }
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int k = 0; k <= 1000; k++)
    {
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                c[i][j] = 0;
                d[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] > 0 && c[i][j] == 0)
                {
                    BFS(i, j, ++cnt);
                }
            }
        }
        if (cnt >= 2) { break; }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] > 0 && d[i][j]==0)
                    melt(i, j);
            }
        }
        t++;
    }
    if (cnt == 0) { cout << "0" << '\n'; }
    else
        cout << t << '\n';
}
