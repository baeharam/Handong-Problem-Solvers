

#include <iostream>
#include <cstdio>

using namespace std;
#define MAX 100000
int N;
int value[2][MAX];
int dp[MAX][3];


int check(int x, int status){
 /*
     status = 0: 아무것도 떼어내지 않음
     status = 1: 위 스티커 떼어냄
     status = 2: 아래 스티커 떼어냄
 */
    int result;
    
    if(x == N) return 0;   //base condition
    if(dp[x][status] != -1) return dp[x][status];  // already calculated
    
    result = check(x+1, 0);
    if(status != 1) result = max(result, value[0][x] + check(x+1,1)); // 위쪽 떼어내기
    if(status != 2) result = max(result, value[1][x] + check(x+1,2)); //아래쪽 떼어내기
    dp[x][status] = result;
    return result;
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;
        for(int r = 0; r < 2; r++)
            for(int c = 0; c < N; c++){
                scanf("%d",&value[r][c]);
            }
        for(int r = 0; r < N; r++)
            for(int c = 0; c < 3; c++)
                dp[r][c] = -1;         // 계산되지 않은 상태
        cout << check(0,0) << "\n";
    }
    
    return 0;
}


