#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct node{
  int weight;
  int from;
  int to;
}Node;

bool operator<(const Node& N1, const Node& N2){
  return N1.weight <N2.weight;
}


Node N[1000001];
int v, e, a, b, c, i, cnt, sum;

int parent[100001];

int find(int x){
  if(x == parent[x])
    return x;
  else
    return parent[x]=find(parent[x]);
}

void unite(int x, int y){
  x = parent[x];
  y = parent[y];
  parent[x] = y;
}

int main(){


  scanf("%d %d", &v, &e);

  for(int i = 0; i<e;i++){
    scanf("%d %d %d", &a, &b, &c);
    N[i] = {c, a, b};
  }
  for(int i = 1; i<=v; i++){
    parent[i] = i;
  }

  sort(N, N+e);
  int j = 0;
  while(cnt!=v-2){
    a = N[j].from;
    b = N[j].to;
    if(find(a) != find(b)){
      unite(a,b);
      cnt++;
      sum += N[j].weight;
    }
    j++;
  }

printf("%d", sum);
return 0;

}
