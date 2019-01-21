// baekjoon 1647 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100001
#define MAX_M 1000001

struct Edge{
	int u, v, w;
	Edge(){u=-1, v=-1, w=0;}
	Edge(int _u, int _v, int _w){ u=_u, v=_v, w=_w;}
	bool operator<(const Edge &e) {
		return w < e.w;
	}
};

int N, M, u, v, w, rst, cnt, root[MAX_N];
Edge e[MAX_M];

int find(int n) {
	if (root[n]==-1) return n;
	return root[n] = find(root[n]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[b] = a;
	return true;
}

int main() {
	scanf("%d%d", &N, &M);
	fill(root, root+N, -1);
	for (int i=0; i<M; i++) {
		scanf("%d%d%d", &u, &v, &w);
		e[i] = Edge(u,v,w);
	}
	sort(e, e+M);
	for (int i=0; i<M; i++) {
		if (merge(e[i].u, e[i].v)) {
			cnt++;
			if (cnt == N-1) break;
			rst += e[i].w;
		}
	}
	printf("%d\n", rst);
	return 0;
}