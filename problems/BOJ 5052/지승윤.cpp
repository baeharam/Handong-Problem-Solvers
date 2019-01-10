#include <stdio.h>
#include <string.h>

int n;

int main() {
	int trie[10005 * 10][10];
	bool fin[10005 * 10];
	char str[12];
	short N, T; for (scanf("%hd", &T); T--;) {
		scanf("%hd\n", &N);
		n = 0;
		memset(trie[0], 0, sizeof(trie[0]));
		bool ans = 1;
		for (register short i = 1; i <= N; i++) {
			fgets(str, 12, stdin);
			if (!ans) continue;
			register int p = 0;
			for (register short j = 0; ans && str[j] != '\n'; j++) {
				register short cur = str[j] - '0';
				if (!trie[p][cur]) {
					++n;
					fin[n] = 0;
					memset(trie[n], 0, sizeof(trie[n]));
					trie[p][cur] = n;
				}
				p = trie[p][cur];
				if (fin[p]) ans = 0;
			}
			if (ans) {
				fin[p] = 1;
				for (register short j = 0; j < 10; j++) {
					if (trie[p][j] > 0) {
						ans = 0;
						break;
					}
				}
			}
		}
		puts(ans ? "YES" : "NO");
	}
}