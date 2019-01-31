#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 10001

vector<vector<int>> v, c;
pair<int, int> back[MAX][2];
vector<int> r;

int n, x, y;
int g[MAX], memo[MAX][2], visit[MAX];

void dfs(int here, int w) {
  visit[here] = 1;
  if (here != 1) {
    c[w].push_back(here);
  }

  for (auto next: v[here]) {
    if (!visit[next])
      dfs(next, here);
  }
}

int solve1(int coordinate, int state) {
  int &ret = memo[coordinate][state];
  if (ret != -1)
    return ret;

  ret = 0;
  if (state) {
    ret = g[coordinate];
    for (auto next : c[coordinate])
      ret += solve1(next, 0);
  }

  else {
    for (auto next : c[coordinate])
      ret += max(solve1(next, 1), solve1(next, 0));

  }
  return ret;
}

void solve2 (int coordinate, int state) {
  if (state) {
    r. push_back(coordinate);
    for (auto next : c[coordinate])
      solve2(next, 0);
  }

  else {
    for (auto next : c[coordinate]) {
      if (memo[next][1] >= memo[next][0])
        solve2(next, 1);

      else
        solve2(next, 0);
    }
  }
}

int main () {
  scanf("%d", &n);

  v.resize(n+1);
  c.resize(n+1);

  memset(memo, -1, sizeof(memo));

  for (int i = 1; i <= n; i++)
    scanf("%d", &g[i]);

  for (int i = 0; i < n-1; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }

  dfs(1, 0);
  int x = solve1(1,0);
  int y = solve1(1,1);

  if (x >= y)
    solve2(1,0);

  else
    solve2(1,1);

  printf("%d\n", max(x, y));
  sort(r.begin(), r.end());
  for (auto h : r)
    printf("%d ", h);

  return 0;
}
