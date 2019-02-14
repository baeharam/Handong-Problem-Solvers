// baekjoon 1655 yechan
#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int> > right_pq;
priority_queue<int> left_pq;

int main() {
	scanf("%d", &N);
	scanf("%d", &x);
	printf("%d\n", x);
	left_pq.push(x);
	for (int i=1; i<N; i++) {
		scanf("%d", &x);
		if (i%2 == 0) {
			right_pq.push(x);
			left_pq.push(right_pq.top());
			right_pq.pop();
		} else {
			left_pq.push(x);
			right_pq.push(left_pq.top());
			left_pq.pop();
		}
		printf("%d\n", left_pq.top());
	}
	return 0;
}