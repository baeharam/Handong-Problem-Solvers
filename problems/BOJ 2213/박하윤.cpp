#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxN = 10001;

vector<vector<int> > edge, chd;
int visited[maxN], dp[maxN][2], n, w[maxN], x, y;
pair<int, int> back[maxN][2];
vector<int> r;

void dfs(int cur, int par){ 
    visited[cur] = 1;
    if(cur != 1) chd[par].push_back(cur);
    for(auto next : edge[cur]){
        if(!visited[next])
            dfs(next, cur);
    }
}

int func(int pos, int state){
    int &ret = dp[pos][state];
    if(ret != -1) return ret;
    ret = 0;
    if(state){
        ret = w[pos];
        for(auto next : chd[pos])
            ret += func(next, 0);
    } else {
        for(auto next : chd[pos])
            ret += max(func(next, 1), func(next, 0));
    }
    return ret;
}

void ff(int pos, int state){
    if(state){
        r.push_back(pos);
        for(auto next : chd[pos])
            ff(next,0);
    } else {
        for(auto next : chd[pos]){
            if(dp[next][1] >= dp[next][0])
                ff(next, 1);
            else ff(next, 0);
        }
    }
}

int main(){
    scanf("%d", &n);
    edge.resize(n + 1);
    chd.resize(n + 1);
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1,0);
    int x = func(1, 0);
    int y = func(1, 1);
    if(x >= y)
        ff(1, 0);
    else 
        ff(1, 1);
    printf("%d\n", max(x, y));
    sort(r.begin(), r.end());
    for(auto h : r)
        printf("%d ", h);
    return 0;   
}