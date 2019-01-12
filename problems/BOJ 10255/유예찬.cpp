// baekjoon 10255 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int T, xmin, ymin, xmax, ymax;

struct Point{
	int x, y;
	Point():x(0), y(0){}
	Point(int x, int y){ this->x=x; this->y=y; }
	bool operator>(const Point &o) { return (o.x == x) ? (y > o.y) : x > o.x; }
	bool operator==(const Point &o) { return (x == o.x) && (y == o.y); }
};

struct Line{
	Point pos[2];
	Line(){};
	Line(Point a, Point b) { pos[0]=a; pos[1]=b; }
	Line(int a, int b, int c, int d) { pos[0] = Point(a, b); pos[1] = Point(c, d); }
};

int getCCW(Point a, Point b, Point c) {
	int res = (a.x*b.y + b.x*c.y + c.x*a.y);
	res -= (a.x*c.y + b.x*a.y + c.x*b.y);
	return (res) ? ((res < 0) ? -1 : 1) : 0;
}

int isISTPoint(Line rline, Line line) {
	int ccw[4];
	Point a = line.pos[0], b = line.pos[1];
	Point c = rline.pos[0], d = rline.pos[1];

	ccw[0] = getCCW(a, b, c), ccw[1] = getCCW(a, b, d);
	ccw[2] = getCCW(c, d, a), ccw[3] = getCCW(c, d, b);

	int ab = ccw[0]*ccw[1], cd = ccw[2]*ccw[3];

	if (!ccw[0] && !ccw[1]) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		if (!ccw[2] && !ccw[3]) {
			if (c > b || a > d) return 0;
			if (b == c || d == a) return 1;
			return -1;
		}
		return 1;
	}
	return !(ab > 0 || cd > 0);
}

int Solve(vector<Line> rect, Line line) {
	int ans = 0, i;
	for (i=0; i<4; i++){
		int tmp = isISTPoint(rect[i], line);
		if (tmp == -1) break;
		ans += tmp;
		if (isISTPoint(Line(rect[i].pos[0], rect[i].pos[0]), line)) ans--;
	}
	if (i < 4) ans = 4;
	return ans;
}

int main() {
	scanf("%d", &T);
	for (int i=0; i<T; i++) {
		vector<Line> rect(4);
		Line line;

		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
		rect[0] = Line(xmin, ymin, xmax, ymin);
		rect[1] = Line(xmax, ymin, xmax, ymax);
		rect[2] = Line(xmax, ymax, xmin, ymax);
		rect[3] = Line(xmin, ymax, xmin, ymin);

		scanf("%d%d%d%d", &xmin, &ymin, &xmax, &ymax);
		line = Line(xmin, ymin, xmax, ymax);

		printf("%d\n", Solve(rect, line));
	}
	return 0;
}