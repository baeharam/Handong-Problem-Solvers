#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
vector<int> e[201];
int cow[201],hom[201];
bool visited[201];
int dfs(int now){
    visited[now]=true;
    for(int there:e[now]){
          if(hom[there]==-1||!visited[hom[there]]&&dfs(hom[there])){
              cow[now]=there;
              hom[there]=now;
          return true;
          }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int s,x;
        scanf("%d",&s);
        for(int j=0;j<s;j++){
            scanf("%d",&x);
            e[i].push_back(x-1);
        }
    }
    int ret=0;
    fill(cow,cow+n,-1);
    fill(hom,hom+m,-1);
    for(int now=0;now<n;now++){
        if(cow[now]==-1){
            fill(visited,visited+n,false);
        
            if(dfs(now))
               ret++;
        }
    }
    printf("%d",ret);
}