#include <cstdio>

const int N = 1000001;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int n, i, j, cnt, fail[N];
char a[N], b[N * 2];

int main() {

	//입력받는 부분
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	 scanf(" %c", &a[i]);

	for (i = 0; i < n; i++)
	 scanf(" %c", &b[i]), b[i + n] = b[i];

	 //KMP알고리즘, pi배열로 스킵하고, substring을 찾는 부분
	for (i = 1, j = 0; i < n; i++) {
		while (j && a[i] != a[j]) j = fail[j - 1];
		if (a[i] == a[j]) fail[i] = ++j;
	}

	for (i = 0, j = 0; i < 2 * n - 1; i++) {
		while (j && b[i] != a[j]) j = fail[j - 1];
		if (b[i] == a[j]) (j == n - 1) ? (j = fail[j], cnt++) : j++;
	}

	int d = gcd(cnt, n);
	printf("%d/%d\n", cnt / d, n / d);

	return 0;
}
