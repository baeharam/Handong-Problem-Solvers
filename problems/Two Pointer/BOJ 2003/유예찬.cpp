// baekjoon 2003 yechan
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int N, cnt;
ll M, x;
set<ll> s;

int main() {
	scanf("%d%lld", &N, &M);
	s.insert(0LL);
	ll prev = 0;
	for (int i=0; i<N; i++) {
		scanf("%lld", &x);
		prev += x;
		s.insert(prev);
		if (s.count(prev-M)) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}