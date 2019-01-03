#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

struct Point{
    int x;
    int y;

    Point(){}
    Point(int x,int y):x(x),y(y){}

    bool operator<(const Point& p) const{
        if(y==p.y) return x<p.x;
        else return y<p.y;
    }
};

typedef std::set<Point>::iterator sit;

inline int dist(const Point& p1, const Point& p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

bool cmp(const Point& p1, const Point& p2){
    return p1.x<p2.x;
}

std::vector<Point> coor;
int n,x,y;

int main(void)
{
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d",&x,&y);
        coor.push_back({x,y});
    }

    // x좌표 정렬
    std::sort(coor.begin(),coor.end(),cmp);

    // 후보
    std::set<Point> candidate{coor[0],coor[1]};
    int ans = dist(coor[0],coor[1]);
    int start = 0;

    for(int i=2; i<n; i++){
        Point now = coor[i];
        // 이전 후보들 검사
        while(start<i){
            int dx = now.x - coor[start].x;
            if(dx*dx > ans){
                candidate.erase(coor[start]);
                start++;
            } else break;
        }

        int d = (int)sqrt((double)ans)+1;

        Point lower = Point(-10001,now.y-d);
        Point upper = Point(10001,now.y+d);

        sit lit = candidate.lower_bound(lower);
        sit uit = candidate.upper_bound(upper);

        for(sit it=lit; it!=uit; it++){
            int d = dist(now,*it);
            ans = std::min(ans,d);
        }
        candidate.insert(now);
    }
    printf("%d",ans);
    return 0;
}