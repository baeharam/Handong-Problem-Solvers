// baekjoon 5676 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int SIZE = 1<<17;

char arr[SIZE*2];
struct SegTree{
	SegTree(){ fill(arr, arr+SIZE*2, 0); }

	char decision(char a, char b) {
		if (a == '0' || b == '0') return '0';
		if (a == '+' && b == '+') return '+';
		if (a == '-' && b == '-') return '+';
		return '-';
	}

	char mul(int L, int R, int nodeNum, int nodeL, int nodeR) {
		if (R < nodeL || nodeR < L) return '+';
		if (L <= nodeL && nodeR <= R) return arr[nodeNum];
		int mid = (nodeL + nodeR) / 2;
		return decision(mul(L,R,nodeNum*2,nodeL,mid), mul(L,R,nodeNum*2+1,mid+1,nodeR));
	}
	char mul(int L, int R) { return mul(L, R, 1, 0, SIZE-1); }

	void update(int i, int val) {
		i+=SIZE;
		if (val > 0) arr[i] = '+';
		else if (val < 0) arr[i] = '-';
		else arr[i] = '0';
		while (i > 1) {
			i/=2;
			arr[i] = decision(arr[i*2], arr[i*2+1]);
		}
	}
};

int main() {
	int N, K;
	while (scanf("%d%d", &N, &K) != -1) {
		SegTree sg;
		for (int i=1; i<=N; i++) {
			int x; scanf("%d", &x);
			sg.update(i, x);
		}
		for (int i=0; i<K; i++) {
			char c; int a, b;
			scanf(" %c %d %d", &c, &a, &b);
			if (c == 'C') sg.update(a, b);
			else printf("%c", sg.mul(a,b));
		}
		puts("");
	}
	return 0;
}