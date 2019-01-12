#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
    int x, y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator < (const Point& rhs) const
    {
        if(x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }

    bool operator == (const Point& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
};

int ccw(const Point& p1, const Point& p2, const Point& p3)
{
    long long x = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}

int check(Point p1, Point a, Point b)
{
    int aa = ccw(p1, a, b);
    int mx = min(a.x, b.x);
    int my = min(a.y, b.y);
    int Mx = max(a.x, b.x);
    int My = max(a.y, b.y);
    if(aa == 0 && mx <= p1.x && p1.x <= Mx && my <= p1.y && p1.y <= My) return 1;
    return 0;
}

int check(Point p1, Point p2, Point a, Point b)
{

    int aa = ccw(p1, p2, a) * ccw(p1, p2, b);
    int bb = ccw(a, b, p1) * ccw(a, b, p2);

    int xx = ccw(p1, p2, a);
    int yy = ccw(p1, p2, b);
    int xxx = ccw(a, b, p1);
    int yyy = ccw(a, b, p2);
    if(aa == 0 && bb == 0){
        if(p2 < p1) swap(p1, p2);
        if(b < a) swap(a, b);
        if(xx == 0 && yy == 0 && xxx == 0 && yyy == 0){
            if(p2 == a || p1 == b) return 1;
            if(p2 < a || b < p1) return 0;
            return -1;
        }
        return 1;
    }

    if(aa > 0 || bb > 0) return 0;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        vector<Point> p(4);
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        p[0] = Point(x1, y1);
        p[1] = Point(x2, y1);
        p[2] = Point(x2, y2);
        p[3] = Point(x1, y2);
        int ans = 0;
        Point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        for(int i = 0; i < 4; ++i){
            int k = check(p[i], p[(i + 1) % 4], a, b);
            if(k < 0){
                ans = 4;
                break;
            }
            int x = check(p[i], a, b);
            ans -= x;
            ans += k;
        }
        cout << ans << '';
    }
}
