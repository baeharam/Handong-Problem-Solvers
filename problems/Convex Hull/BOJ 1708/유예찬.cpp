// baekjoon 1708 yechan
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX_N = 100001;
const int MAX_INF = 40001;

struct Point{
	int x, y;
	int dx, dy;

	Point(int x, int y, int dx, int dy): x(x), y(y), dx(dx), dy(dy){}
	Point(): Point(0, 0, 1, 0){}
	Point(int x, int y): Point(x, y, 1, 0){}

	bool operator<(const Point &o){
		if (1LL*dy*o.dx != 1LL*o.dy*dx) return 1LL*dy*o.dx < 1LL*o.dy*dx;
		if (dy != o.dy) return dy < o.dy;

		return dx < o.dx;
	}
};

bool ccw(const Point &a, const Point &b, const Point &c) {
	long long x = 1LL*a.x*b.y + 1LL*b.x*c.y + 1LL*c.x*a.y;
	x -= 1LL*a.y*b.x + 1LL*b.y*c.x + 1LL*c.y*a.x;
	return x > 0;
}

int N;
Point pos[MAX_N];

int main() {
	scanf("%d", &N);
	int minPos = 0, minX = MAX_INF, minY=MAX_INF;
	for (int i=0; i<N; i++) {
		scanf("%d%d", &pos[i].x, &pos[i].y);
		if (pos[i].y < minY) {
			minPos = i;
			minY = pos[i].y;
			minX = pos[i].x;
		} else if (pos[i].y < minY){
			if (pos[i].x < minX) {
				minPos = i;
				minX = pos[i].x;
			}
		}
	}
	swap(pos[0], pos[minPos]);

	int cnt_x = pos[0].x;
	int cnt_y = pos[0].y;
	for (int i=1; i<N; i++) {
		pos[i].dx = pos[i].x - cnt_x;
		pos[i].dy = pos[i].y - cnt_y;
	}

	sort(pos+1, pos+N);

	stack<int> st;
	st.push(0);
	st.push(1);
	int next = 2;
	while (next < N) {
		while (st.size() >= 2) {
			int first = st.top();
			st.pop();
			int second = st.top();
			if (ccw(pos[second], pos[first], pos[next])) {
				st.push(first);
				break;
			}
		}
		st.push(next++);
	}
	printf("%d\n", st.size());
	return 0;
}