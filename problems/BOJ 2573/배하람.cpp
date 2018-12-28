#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int n,m,h;
int visit[300][300],height[300][300];
queue<pii> q;
pii b;

void bfs(pii v)
{
    int x[4] = {-1,0,1,0};
    int y[4] = {0,-1,0,1};

    q.push(v);
    visit[v.first][v.second] = 1;

    while(!q.empty()) {
        pii s = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int _x = s.first + x[i];
            int _y = s.second + y[i];

            if((_x<0 || _x>=n) || (_y<0 || _y>=m)) continue;
            if(visit[_x][_y]) continue;
            if(!height[_x][_y] && height[s.first][s.second])
                height[s.first][s.second]--;
            else if(height[_x][_y]){
                visit[_x][_y] = 1;
                q.push({_x,_y});
            }
        }
        if(height[s.first][s.second])
            b = s;
    }

}

int main(void)
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d",&h);
            height[i][j] = h;
            if(height[i][j] && !(b.first&&b.second)) 
                b = {i,j};
        }
    }

    int year = 0;
    bool ans = false;
    while(height[b.first][b.second]) {
        bfs(b);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(height[i][j] && !visit[i][j])
                    ans = true;
                visit[i][j] = 0;
            }
        }
        if(ans) break;
        year++;
    }
    printf("%d\n",ans?year:0);
    return 0;
}