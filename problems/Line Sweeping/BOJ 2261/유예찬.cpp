// baekjoon 2261 yechan
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>
#include <cmath>
using namespace std;
#define MAX_N 100000
#define MAX_V 10001
#define SQ(x) (x)*(x)

struct Point{
	int x, y;
	Point(){}
	Point(int x, int y):x(x),y(y){}

	bool operator<(const Point& p) const{
		if (y==p.y) return x<p.x;
		else return y<p.y;
	}
};

typedef set<Point>::iterator sit;

int N, start;
Point point[MAX_N];

inline int dist(const Point& a, const Point& b){ 
	return SQ(a.x-b.x)+SQ(a.y-b.y);
}

bool cmp(const Point& a, const Point& b) {
	return a.x<b.x;
}

int main() {
	scanf("%d",&N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &point[i].x, &point[i].y);

	sort(point, point+N, cmp);

	set<Point> s{point[0], point[1]};
	int result = dist(point[0], point[1]);

	for (int i=2; i<N; i++) {
		while (start < i) {
			int dx = point[i].x - point[start].x;
			if (SQ(dx) > result) s.erase(point[start++]);
			else break;
		}

		int d = (int)sqrt((double)result) + 1;
		sit lit = s.lower_bound({-MAX_V, point[i].y-d});
		sit uit = s.upper_bound({MAX_V, point[i].y+d});

		for (sit it=lit; it!=uit; it++)
			result = min(result, dist(point[i], *it));

		s.insert(point[i]);
	}
	printf("%d\n", result);
	return 0;
}