#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>
#define x first
#define y second

using namespace std;

int n;
set<pair<int, int>> s;
pair<int, int> N[100000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &N[i].x, &N[i].y);
	sort(N, N + n);
	int ans = 2e9;
	for (int i = 0, idx = 0; i < n; i++) {
		int d = sqrt(ans);
		while (N[i].x - N[idx].x > d) s.erase({ N[idx].y, N[idx++].x });
		for (auto j = s.lower_bound({ N[i].y - d, -10000 }); j != s.end() && j->x <= N[i].y + d; j++)
			ans = min(ans, (N[i].x - j->y) * (N[i].x - j->y) + (N[i].y - j->x) * (N[i].y - j->x));
		s.insert({ N[i].y,N[i].x });
	}
	printf("%d\n", ans);
	return 0;
}