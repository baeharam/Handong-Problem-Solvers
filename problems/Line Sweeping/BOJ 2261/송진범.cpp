#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point {
    int x, y;
    Point() {
    }
    Point(int x, int y) : x(x), y(y) {
    }
    bool operator < (const Point &v) const {
        if (y == v.y) {
            return x < v.x;
        } else {
            return y < v.y;
        }
    }
};
bool cmp(const Point &u, const Point &v) {
    return u.x < v.x;
}
int dist(Point p1, Point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}
int main() {
    int n;
    scanf("%d",&n);
    vector<Point> a(n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].x,&a[i].y);
    }
    sort(a.begin(), a.end(), cmp);
    set<Point> candidate = {a[0], a[1]};
    int ans = dist(a[0], a[1]);
    int start = 0;
    for (int i=2; i<n; i++) {
        Point now = a[i];
        while (start < i) {
            auto p = a[start];
            int x = now.x - p.x;
            if (x*x > ans) {
                candidate.erase(p);
                start += 1;
            } else {
                break;
            }
        }
        int d = (int)sqrt((double)ans)+1;
        auto lower_point = Point(-100000, now.y-d);
        auto upper_point = Point(100000, now.y+d);
        auto lower = candidate.lower_bound(lower_point);
        auto upper = candidate.upper_bound(upper_point);
        for (auto it = lower; it != upper; it++) {
            int d = dist(now, *it);
            if (d < ans) {
                ans = d;
            }
        }
        candidate.insert(now);
    }
    printf("%d\n",ans);
    return 0;
}
