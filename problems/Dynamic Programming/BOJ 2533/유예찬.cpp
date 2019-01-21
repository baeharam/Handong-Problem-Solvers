// baekjoon 2533 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 1000001
int N;
int dp[MAX_N][2];
bool visited[MAX_N];
vector<int> adj[MAX_N];
vector<int> child[MAX_N];

void getchild(int root) {
	visited[root] = true;
	for (int i=0; i<adj[root].size(); i++) {
		int next = adj[root][i];
		if (!visited[next]) {
			child[root].push_back(next);
			getchild(next);
		}
	}
}

int dfs(int root, int state) {
	if (dp[root][state]) return dp[root][state];
	if (!child[root].size()) return dp[root][state] = state;
	if (state) {
		int ret=0;
		for (int i=0; i<child[root].size(); i++) {
			int next = child[root][i];
			ret += min(dfs(next,0), dfs(next,1));
		}
		return dp[root][state] = ret + 1;
	}
	else {
		int ret=0;
		for (int i=0; i<child[root].size(); i++) {
			int next = child[root][i];
			ret += dfs(next, 1);
		}
		return dp[root][state] = ret;
	}
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	getchild(1);
	printf("%d\n", min(dfs(1,0), dfs(1,1)));
	return 0;
}


/*
// baekjoon 2533 reference
#include <cstdio>

using namespace std;

char s[15000000];

inline void init() { fread(s, 1, sizeof(s), stdin); }
inline void readN(int &r)
{
	static char *p = s;
	while (*p < 48) p++;
	for (r = *p & 15; *++p & 16; r = r * 10 + (*p & 15));
}

int p[2000002];
int q[2000002];
int r;

int g[1000001];
int c[1000001];
int d[1000001];

void f(int x, int y)
{
	int i;
	d[x] = 1;
	for (i = g[x]; i; i = q[i]) if (p[i] != y)
	{
		f(p[i], x);
		c[x] += d[p[i]];
		d[x] += c[p[i]];
	}
	if (c[x] > d[x]) c[x] = d[x];
}

int main()
{
	int i, j, n;
	init();
	readN(n);
	while (--n)
	{
		readN(i);
		readN(j);
		r++;
		p[r] = j;
		q[r] = g[i];
		g[i] = r;
		r++;
		p[r] = i;
		q[r] = g[j];
		g[j] = r;
	}
	f(1, 1);
	printf("%d", c[1]);
}
 */