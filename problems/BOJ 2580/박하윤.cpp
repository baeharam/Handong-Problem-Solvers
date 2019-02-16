#include <cstdio>
#include <vector>
using namespace std;

typedef pair <int, int> P;
vector <P> z;
int map[9][9];
bool flag;

void printAll(){
    for(int i = 0 ; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ", map[i][j]);
        }
    printf("\n");
    }
}

bool isPromising(int n, int x, int y){
   for(int i = 0; i < 9; i++){
        if(map[x][i] == n || map[i][y] == n)
            return false;
    }
    int startX = (x / 3) * 3;
    int startY = (y / 3) * 3;

    for(int i = startX; i < startX + 3; i++){
        for(int j = startY; j < startY+3; j++){
            if(map[i][j] == n)
                return false;
        }
    }
    return true;
}

void dfs(int idx){
    if(flag) return;

    if(idx == z.size()){
        printAll();
        flag = true;
    } 
    else {
        int a = z[idx].first;
        int b = z[idx].second;

        for(int i = 1; i <= 9; i++){
            if(isPromising(i, a, b)){
                map[a][b] = i;
                dfs(idx+1);
                map[a][b] = 0;
            }
        }
    }
}

int main(){
    for(int i = 0 ; i < 9; i++)
        for(int j = 0; j < 9; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0) z.push_back(P(i, j));
        }
    flag = false;
    dfs(0);
}