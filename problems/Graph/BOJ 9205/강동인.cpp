#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;


int n, m;
int dist[50][5100][2];
int visited[105];
string ans;

bool distance (int x1, int y1, int x2, int y2) {
    int diff = abs(x1 - x2) + abs(y1 - y2);
    return (diff <= 1000) ? true : false;
}

void dfs(int N, int idx) {
    if(idx == m + 1) {
        ans = "happy";
        return;
    }
    
    for(int i = 1; i < m + 2; i ++) {
        if(!visited[i]) {
            
            if(distance(dist[N][idx][0], dist[N][idx][1], dist[N][i][0], dist[N][i][1])) {
                visited[i] = 1;
        
                dfs(N, i);
            }
        }
    }
}

int main() {
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        
        ans = "sad";
        memset(visited, 0, sizeof(visited));
        for (int j = 0; j < m+2; j++) {
            scanf("%d %d", &dist[i][j][0], &dist[i][j][1]);
        }
        dfs(i, 0);
        cout << ans << endl;
    }
    
}



