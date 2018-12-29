#include <cstdio>
#include <cstring>
using namespace std;

int N, M, bing[301][301];
bool visited[301][301];
int dx[4] = {0, 0, 1, -1};// colum의 위치조절을 위해
int dy[4] = {1, -1, 0, 0};// row의 위치조절을 위해 

void DFS(int r, int c)
{
    visited[r][c] = true;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dy[i];
        int nc = c + dx[i];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc])
            continue;
        if (bing[nr][nc] == 0) 
            continue;
        DFS(nr, nc);
    }
}

int melt(int r, int c)
{
    int num = 0;
    for(int i = 0; i < num; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
        if(bing[nr][nc] == 0)
            num++;
    }
    return num;
}

int main()
{
    // 행과 열 입력받고 각각의 행과 열의 값을 입력
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            scanf("%d", &bing[i][j]);
    
    while(1)
    {
        int year = 0, cnt = 0;
        int meltBing[301][301];
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(!visited[i][j] && bing[i][j] > 0){
                    cnt++;      // 빙산 갯수 세기
                    DFS(i, j);
                }
                if(bing[i][j] == 0) continue;
                meltBing[i][j] = bing[i][j] - melt(i, j);// 빙산이 녹는것 
                if(meltBing[i][j] < 0) meltBing[i][j] = 0;
                bing[i][j] = meltBing[i][j]; // 녹은 빙산의 높이를 지정  
            }
        }
        if(cnt == 0){
            printf("0\n");
            break;
        }
        if(cnt >= 2){
            printf("%d\n", year);
            break;
        }
        year++;
    }
}