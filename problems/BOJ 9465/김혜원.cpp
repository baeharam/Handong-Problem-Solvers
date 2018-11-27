#include<iostream>
using namespace std;

int score[2][100000];
int T, n;

int max(int a, int b) {
    return a > b ? a : b;
}
    
int main(void)
{
    cin >> T;
    while(T-->0){
        cin >> n;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < n; j++){
                cin >> score[i][j];
            }
        }

        for(int i=1; i<=n; i++){
          //왼쪽 아래부터 시작
          score[0][i] = max(score[1][i-1]+score[0][i], score[0][i-1]);
          //왼쪽 위부터 시작
          score[1][i] = max(score[0][i-1]+score[1][i], score[1][i-1]);
        }
        cout<<max(score[0][n],score[1][n]);
    }
}

