#include <cstdio>
#include <algorithm>

int tc,xmin,ymin,xmax,ymax,x1,y1,x2,y2;

struct Point{
    int x;
    int y;

    bool operator==(const Point& p) const{
        return x==p.x && y==p.y;
    }

    bool operator<(const Point& p) const{
        if(x!=p.x) return x<p.x;
        else return y<p.y;
    }
};

Point a,b;
Point left_bottom,right_bottom,left_top,right_top;

inline int cross_product(Point a, Point b){
    return a.x*b.y-a.y*b.x;
}

int ccw(Point a, Point b, Point c){
    Point a_b = {b.x-a.x,b.y-a.y};
    Point a_c = {c.x-a.x,c.y-a.y};
    return cross_product(a_b,a_c);
}

int intersect_num(Point dir1, Point dir2){
    int ccw1 = ccw(a,b,dir1), ccw2 = ccw(a,b,dir2);
    int ccw3 = ccw(dir1,dir2,a), ccw4 = ccw(dir1,dir2,b);

    // 선분과 직사각형의 변이 일직선 상에 놓인 경우
    // 일차원 좌표계로 계산해도 상관없음
    if(!ccw1 && !ccw2){

        if(b<a) std::swap(a,b);
        if(dir2<dir1) std::swap(dir1,dir2);

        if(ccw1==0&&ccw2==0&&ccw3==0&&ccw4==0){
            if(b<dir1 || dir2<a) return 0;
            if(b==dir1 || dir2==a) return 1;
            return -1;
        }
        return 1;
    }

    // 일직선이 아닌 경우
    if((ccw1>0&&ccw2>0) || (ccw3>0&&ccw4>0) || (ccw1<0&&ccw2<0) || (ccw3<0&&ccw4<0)) return 0;
    else return 1;
}

int main(void)
{
    scanf("%d",&tc);

    while(tc--){
        scanf("%d%d%d%d",&xmin,&ymin,&xmax,&ymax);
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        a = {x1,y1};
        b = {x2,y2};
        
        left_bottom = {xmin,ymin};
        right_bottom = {xmax,ymin};
        left_top = {xmin,ymax};
        right_top = {xmax,ymax};

        Point p[4][2] = {
            {left_bottom,left_top},
            {right_bottom,left_bottom},
            {left_top,right_top},
            {right_top,right_bottom}
        };

        int ans = 0,i;
        for(i=0; i<4; i++){
            int inter = intersect_num(p[i][0],p[i][1]);
            if(inter==-1) break;
            ans += inter;
            if(intersect_num(p[i][0],p[i][0])) ans--;
        }
        printf("%d\n",i<4?4:ans);
    }
    return 0;
}