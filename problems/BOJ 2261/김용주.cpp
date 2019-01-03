#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
struct point{
	int x, y;
	point() {}
	point(int x, int y) : x(x), y(y){}
	bool operator < (const point &v) const{
		if (y == v.y) return x < v.x;
		else return y < v.y;
	}
};
int n, x, y, d;
vector<point> v;
set<point> s;

bool cmp(const point &a, const point &b){
	return a.x < b.x;
}
int getDist(point a, point b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		v.push_back(point(x,y));
	}
	sort(v.begin(), v.end(), cmp);
	d = getDist(v[0], v[1]);
	int er = 0;
	for(int i = 0; i < n; i++){
		//그 다음 점의 x값과 이전에 있던 점들의 x값의 차가 d보다 크면 set에서 지움으로써 무시.
		for(int j = er; j < i; j++){
			if((v[i].x - v[j].x)*(v[i].x - v[j].x) > d){
				s.erase(v[j]);
				er++;
			}
			else break;
		}
		int dist = (int)sqrt((double)d) + 1;
		//x의 범위는 위에서 정했고, y의 범위를 +- d만큼으로 설정
		point lower_point = point(-100000, v[i].y - dist);
		point upper_point = point(100000, v[i].y + dist);
		//lower point가 시작되는 구간을 가리킴
		auto l = s.lower_bound(lower_point);
		auto u = s.upper_bound(upper_point);
		for(auto it = l; it != u; it++)
			d = min(d, getDist(*it, v[i]));
		s.insert(v[i]);
	}
	printf("%d\n", d);
	return 0;
}