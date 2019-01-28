#include <cstdio>
#include <queue>

struct monkey{
    int x;
    int y;
    int num;
    int knum;
};

std::queue<monkey> q;

int k,w,h,_x,_y,_num,_knum;
int a[201][201];
int visit[201][201][30];

int kx[8] = {-2,-2,-1,1,2,2,-1,1};
int ky[8] = {-1,1,2,2,-1,1,-2,-2};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs(int x, int y)
{
    q.push({x,y,0,0});
    visit[0][0][0] = 1;

    while(!q.empty()){
        monkey m = q.front();
        _x = m.x, _y = m.y, _num = m.num, _knum = m.knum;
        if(_x==h-1 && _y==w-1) break;
        q.pop();
        if(_knum < k){
            for(int i=0; i<8; i++){
                int _kx = _x+kx[i], _ky = _y+ky[i];
                if(_kx<0 || _kx>=h || _ky<0 || _ky>=w) continue;
                if(a[_kx][_ky]==1 || visit[_kx][_ky][_knum+1]) continue;
                visit[_kx][_ky][_knum+1] = 1;
                q.push({_kx,_ky,_num+1,_knum+1});
            }
        }
        for(int i=0; i<4; i++){
            int _dx = _x+dx[i], _dy = _y+dy[i];
            if(_dx<0 || _dx>=h || _dy<0 || _dy>=w) continue;
            if(a[_dx][_dy]==1 || visit[_dx][_dy][_knum]) continue;
            visit[_dx][_dy][_knum] = 1;
            q.push({_dx,_dy,_num+1,_knum});
        }
    }
    return q.size() ? _num : -1;
}


int main(void)
{
    scanf("%d%d%d",&k,&w,&h);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("%d",bfs(0,0));
    return 0;
}