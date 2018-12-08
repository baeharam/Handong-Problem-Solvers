#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

vector<int> a[100];
queue<int> q;
int visit[100];
int n,m;
int p1,p2;

int bfs(int start){
  int result = -1;
  visit[start]= false;
  q.push(start);
  
  while(!q.empty()){
    int j = q.front();
    q.pop();
    //cout<<j<<" ";
    for(int i=0; i<a[j].size(); i++){
      int next = a[j][i];
      if(visit[next] == false){
        visit[next] = visit[j]+1;
        q.push(next);
      }

      if(next == p2)
      result = visit[next];
    }

  }
 return result;
}

int main() {
  int x,y;

  scanf("%d", &n);
  scanf("%d %d", &p1, &p2);
  scanf("%d", &m);

  for(int i=0; i<m; i++){
    scanf("%d %d",&x,&y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
  printf("%d", bfs(p1));
}
