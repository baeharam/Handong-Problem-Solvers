#include <bits/stdc++.h>
using namespace std;
int D[105][105][2], T, N, S;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    D[1][0][0] = 1;
    D[1][0][1] = 1;
    for(int i = 1; i < 100; i++){
        for(int j = 0; j <= i-1; j++){
            D[i+1][j][0] += D[i][j][0] + D[i][j][1];
            D[i+1][j][1] += D[i][j][0];
            D[i+1][j+1][1] += D[i][j][1];
        }
    }
    cin>>T;
    while(T--){
        cin>>N>>S;
        cout<<D[N][S][0]+D[N][S][1]<<"\n";
    }
}