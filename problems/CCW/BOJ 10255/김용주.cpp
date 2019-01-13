//BOJ10255_Odsn
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

//operator는 이 struct를 비교하게 해주는 용도. struct의 크고 같음을 알 수 없기에.
struct Point
{
	int x, y;
	Point():x(0), y(0){}
	Point(int x, int y){ this->x=x; this->y=y; }

    bool operator<(const Point& a) const{
        if(x != a.x) return x < a.x;
        else return y < a.y;
    }

	bool operator==(const Point& a) const{
        return x == a.x && y == a.y;
    }
};

// 시계방향 = -1, 반시계 = 1, 일직선 = 0
int ccw(Point &a, Point &b, Point &c){
	int temp = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if(temp > 0) return 1;
	else if(temp < 0) return -1;
	else return 0;
}

//교점이 없음 = 0, 교점이 있음 = 1, 교점이 무수히 많음 = -1
int intersection(Point a, Point b, Point c, Point d){
	int cc[4];
	cc[0] = ccw(a,b,c), cc[1] = ccw(a,b,d);
	cc[2] = ccw(c,d,a), cc[3] = ccw(c,d,b);

	int line1 = cc[0]*cc[1], line2 = cc[2]*cc[3];

	if(!cc[0] && !cc[1]){
		if(b < a) swap(a, b);
		if(d < c) swap(c, d);
		if(!cc[2] && !cc[3]){
			if(b < c || d < a) return 0;
			if(b == c || d == a) return 1;
			return -1;
		}
		return 1;
	}

	if((cc[0] == cc[1]) || (cc[2] == cc[3])) return 0;
	else return 1;
}

int main(){
	int T, xmin, ymin, xmax, ymax;
	scanf("%d", &T);

	while(T--){
		vector<Point> p(4);
		scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
		p[0] = Point(xmin, ymin);
		p[1] = Point(xmax, ymin);
		p[2] = Point(xmax, ymax);
		p[3] = Point(xmin, ymax);
		Point Rect[4][2] = {
			{p[0], p[1]},
			{p[1], p[2]},
			{p[2], p[3]},
			{p[3], p[0]}
		};

		scanf("%d %d %d %d", &xmin, &ymin, &xmax, &ymax);
		Point a = Point(xmin, ymin);
		Point b = Point(xmax, ymax);

		int ans = 0;
		for(int i = 0; i < 4; i++){
			int check = intersection(a, b, Rect[i][0], Rect[i][1]);
			if(check == -1) {
				ans += 10;
				break;
			}
			ans += check;
			if(intersection(a, b, Rect[i][0], Rect[i][0])) ans--;
		}
		if(ans > 4) ans = 4;
		printf("%d\n", ans);
	}

	return 0;
}