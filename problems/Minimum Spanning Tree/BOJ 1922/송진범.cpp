#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct kruskal{
  int x, y, d;
}ks; //크루스칼 알고리즘을 사용할 것임

int parent [10000];
int mst; //최종 만들어질 나무
vector<ks> edge; //각 노드를 담은 edge

bool compare(ks n1, ks n2){ //sort에 사용할 compare함수
  return n1.d <n2.d;
}

int find(int num){ //크루스칼에서의 headfind
  if(num == parent[num])
      return num;
  return parent[num] = find(parent[num]);
}

int main()
{
  int N , M = 0;
  cin >> N >> M;

  for(int i = 0; i< N; i++)
    parent[i] = i;

  for(int i = 0; i< M ; i++)
  {
    ks ks;
    scanf("%d %d %d", &ks.x, &ks.y,&ks.d);
    edge.push_back(ks);
  }


  sort(edge.begin(), edge.end(), compare); //거리를 기준으로 정렬

  for(int i = 0; i< M; i++)
  {
    int nx = find(edge[i].x); //x의 헤드를 찾고
    int ny = find(edge[i].y); //Y의 헤드를 찾아서

    if(nx == ny)  //동일하면 계속
      continue;

    parent[nx] = ny; //값에 따라 더해줌
    mst += edge[i].d;
  }
  printf("%d", mst);

    return 0;
}
