#include <cstdio>
#include <algorithm>
using namespace std;
int tree[262144];
int szz;

void init(int i) {
	if (i >= szz) return;
	init(i * 2), init(i * 2 + 1);
	tree[i] = tree[i * 2] * tree[i * 2 + 1];
}

void update(int i, int val) {
	i += szz - 1;
	tree[i] = val;
	i /= 2;

	while (i) {
		tree[i] = tree[i * 2] * tree[i * 2 + 1];
		i /= 2;
	}
}

int find(int i, int l, int r, int ll, int rr) {
	if (l > rr || r < ll) return 1;
	if (ll >= l && rr <= r) return tree[i];
	return find(i * 2, l, r, ll, (ll + rr) / 2) * find(i * 2 + 1, l, r, (ll + rr) / 2 + 1, rr);
}

int main() {
	int n, m, a, b, temp;
	char c;
	
	while (scanf("%d %d", &n, &m) != EOF) {
		szz = 1;
		while (szz < n) szz *= 2;

		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (temp > 0) tree[i + szz] = 1;
			else if (!temp) tree[i + szz] = 0;
			else tree[i + szz] = -1;
		}
		init(1);

		while (m--) {
			scanf(" %c %d %d", &c, &a, &b);
			if (c == 'C') {
				if(b > 0) b = 1;
				else if(!b) b = 0;
				else b = -1;
				update(a, b);
			}
			else {
				temp = find(1, a, b, 1, szz);
				if (temp > 0) printf("+");
				else if (!temp) printf("0");
				else printf("-");
			}
		}
		printf("\n");
	}
}