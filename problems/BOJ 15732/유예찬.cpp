// baekjoon 15732 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 10001;
const int MAX_INF = 1000001;
typedef long long ll;

struct Sequence{
	int start, end, step;
	Sequence():Sequence(0,0,0){}
	Sequence(int start, int end, int step):start(start), end(end), step(step){}
	ll getPos(int pos) {
		if (pos < start) return 0;
		return (min(pos, end) - start)/step + 1;
	}
};

int N, K, ret;
ll D;
Sequence seq[MAX_N];

ll getIdx(int pos) {
	ll cnt = 0;
	for (int i=0; i<K; i++)
		cnt += seq[i].getPos(pos);
	return cnt;
}

int main() {
	scanf("%d%d%lld", &N, &K, &D);
	for (int i = 0; i < K; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		seq[i] = Sequence(x, y, z);
	}

	int ret = MAX_INF;
	ll left = 0, right = MAX_INF;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (D <= getIdx(mid)) {
			ret = min(ret, mid);
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}