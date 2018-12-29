#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <cstring>

using namespace std;

#define MAX_SIZE 100
#define INF 0x7fffffff
#define CENDL "\n"
#define ll long long

int n, m;

int board[301][301];
int board2[301][301];
bool visited[301][301];

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int next() {
    int sum = 0;
    memset(board2, 0, sizeof(board2));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {

            int cand = 0;
            if(board[i][j] > 0) {
                for(int xx =0; xx<4; xx++) {

                    int ax = i + dx[xx];
                    int ay = j + dy[xx];

                    if (ax < 0 || ay < 0 || ax >= n || ay >= m) {
                        continue;
                    }

                    if (board[ax][ay] == 0) {
                        cand++;
                    }
                }

                board2[i][j] = board[i][j] - cand;

                if (board2[i][j] < 0) {
                    board2[i][j] = 0;
                }
            }

            sum += cand;
        }
    }

    memcpy(board, board2, sizeof(board));
    return sum;
}

void dfs(int x, int y)  {

    visited[x][y] = true;

    for(int i=0; i<4; i++) {
        int ax = x + dx[i];
        int ay = y + dy[i];

        if (ax < 0 || ay < 0 || ax >= n || ay >= m) {
            continue;
        }

        if (board[ax][ay] == 0 || visited[ax][ay]) {
            continue;
        }

        dfs(ax, ay);
    }
}

int main() {

    cin.tie(0);
    std::ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
        }
    }

    int sol = 0;
    while(true) {

        int area = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (!visited[i][j] && board[i][j] != 0) {
                    dfs(i, j);
                    area++;
                }
            }
        }


        memset(visited, 0, sizeof(visited));
 
        if (area >= 2) {
            cout << sol << "\n";
            return 0;
        }

        int cand = next();
        if (cand == 0) {
            cout << 0 << "\n";
            return 0;
        }

        sol++;
    }

    cout << sol << CENDL;
    return 0;
}
