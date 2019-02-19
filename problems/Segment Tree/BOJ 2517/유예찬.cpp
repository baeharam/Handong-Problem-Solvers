// baekjoon 2517 yechan
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int SIZE = 1<<19;
const int MAX_N = 500001;
struct Runner{
	int idx, perf;
	Runner():Runner(0,0){}
	Runner(int idx, int perf):idx(idx), perf(perf){}
	bool operator<(const Runner& O) {
		return idx < O.idx;
	}
};

bool perfcmp(const Runner &A, const Runner &O) {
	if (A.perf == O.perf) return A.idx < O.idx;
	return A.perf > O.perf;
}


int N;
Runner data[MAX_N];

int arr[SIZE*2];

struct SegTree{
	int sum(int L, int R, int nodeNum, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return 0;
		if (L <= nodeL && nodeR <= R) return arr[nodeNum];
		int mid = (nodeL + nodeR) / 2;
		return sum(L, R, nodeNum*2, nodeL, mid) + sum(L, R, nodeNum*2+1, mid+1, nodeR);
	}
	int sum(int L, int R) { return sum(L, R, 1, 0, SIZE-1); }

	void update(int i, int val) {
		i += SIZE;
		arr[i]=val;
		while (i > 1) {
			i /= 2;
			arr[i] = arr[i*2]+arr[i*2+1];
		}
	}
};

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &data[i].perf);
		data[i].idx=i;
	}
	sort(data+1, data+N+1, perfcmp);

	for (int i=1; i<=N; i++)
		data[i].perf=i;
	sort(data+1, data+N+1);

	SegTree sg;
	for (int i=1; i<=N; i++) {
		sg.update(data[i].perf, 1);
		printf("%d\n", sg.sum(1, data[i].perf));
	}
	return 0;
}