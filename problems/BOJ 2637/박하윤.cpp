#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int toy[101][101], in[101];

vector<vector<pair<int, int>>> vt;
int main(){
    int n, m;
    int x, y, k;
    scanf("%d %d", &n, &m);
    vt.resize(n+1);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &x, &y, &k);  //-> x를 만들기 위해 y가 k개 필요
        vt[y].emplace_back(x,k);
        in[x]++;
    }
    queue<int> qu;
    for(int i = 1; i <= n; i++){
        if(!in[i]){
            qu.push(i);
            toy[i][i] = 1;
        }
    }
    while(!qu.empty()){
        int cur = qu.front();
        qu.pop();
        for(auto next : vt[cur]) {
            for(int i = 1; i <= n; i++)
                toy[next.first][i] += next.second*toy[cur][i];
            in[next.first]--;
            if(!in[next.first])
                qu.push(next.first);
        }
    }
    for(int i = 1; i <= n; i++){
        if(toy[n][i])
            printf("%d %d\n", i, toy[n][i]);
    }
    return 0;
}