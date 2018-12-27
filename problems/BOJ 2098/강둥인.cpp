#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int N, start, W[16][16], DP[16][65536];
int INF = 9999999;


int getShortestPath(int current, int visited){
    if(visited == (1 << N) -1)
        return W[current][start] ? W[current][start] : INF;
    
    int &ret = DP[current][visited];
    
    if(ret != -1)
        return ret;
    
    ret = INF;
    for(int i = 0; i < N; i++){
        if(visited & (1 << i))
            continue;
        
        if(W[current][i] == 0)
            continue;
        
        ret = min(ret, getShortestPath(i, visited | (1 << i)) + W[current][i]);
    }
    return ret;
}

int main(){
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> W[i][j];
    
    memset(DP, -1, sizeof(DP));
    
    cout << getShortestPath(0, 1);
}
