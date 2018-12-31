// baekjoon 11585 yechan
#include <cstdio>
using namespace std;
#define MAX_N 1000002

char a[MAX_N*2], b[MAX_N];
int N, m, cnt, f[MAX_N];

int gcm(int a, int b) {
	int mod = a%b;
	while (mod > 0) {
		a = b;
		b = mod;
		mod = a % b;
	}
	return b;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf(" %c", &a[i]), a[i+N] = a[i];
	
	for (int i=0; i<N; i++)
		scanf(" %c", &b[i]);

	for (int i=1, j = 0; i < N; i++) {
		while (j && b[i] != b[j]) j = f[j - 1];
		if (b[i] == b[j]) f[i] = ++j;
	}

	for (int i=0, j=0; i<2*N-1; i++) {
		while (j && (a[i] != b[j])) j = f[j - 1];
		if (a[i] == b[j]) {
			if (j == N - 1) cnt++, j = f[j];
			else j++;
		}
	}

	m = gcm(cnt, N);
	printf("%d/%d\n", cnt/m, N/m);
	return 0;
}