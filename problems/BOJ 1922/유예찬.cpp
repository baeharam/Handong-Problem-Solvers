// baekjoon 1922 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define MAX_N 1001
#define MAX_M 100001
typedef pair<int,int> P;

typedef struct _TAG_NODE{
	int a, b, weight;
}__NODE;

int N, M, result, root[MAX_N];

__NODE node[MAX_M];

int find(int n) {
	if(root[n] < 0) return n;
	root[n] = find(root[n]);
	return root[n];
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	root[b] = a;
	return true;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	priority_queue<P, vector<P>, greater<P>> pq;
	fill(root, root+MAX_N, -1);

	for (int i=0; i<M; i++) {
		scanf("%d %d %d", &node[i].a, &node[i].b, &node[i].weight);
		pq.push(P(node[i].weight, i));
	}

	for (int i=0; i<M; i++) {
		int curr = pq.top().second;
		pq.pop();
		int a = node[curr].a;
		int b = node[curr].b;
		int weight = node[curr].weight;
		if (merge(a, b)) {
			result += weight;
		}
	}
	printf("%d\n", result);
	return 0;
}