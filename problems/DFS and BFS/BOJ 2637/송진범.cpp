#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, need[101][101], ind[101];
int x, y, z;
bool check[101];

vector<vector<pair<int,int>>> list;

int main(){
  scanf("%d %d", &n, &m);

  list.resize(n+1);

  for(int i = 0; i<m; i++){
    scanf("%d %d %d", &x, &y, &z);
    list[y].push_back({x,z});
    ind[x]++;
  }

  queue<int> q;
  for(int i = 0; i<=n ; i++){
    if(!ind[i]){
      check[i] = true;
      q.push(i);
      need[i][i] = 1;
    }
  }

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(int i = 0; i<list[current].size();i++){
      int next = list[current][i].first;
      int cost = list[current][i].second;
      for(int j = 1; j<=n;j++){
        need[next][j] +=need[current][j] * cost;
      }

      ind[next]--;
      if(ind[next] ==0)
        q.push(next);
    }
  }

  for(int i = 1; i<=n;i++){
    if(check[i])
    {
      printf("%d %d\n", i, need[n][i]);
    }
  }
}
