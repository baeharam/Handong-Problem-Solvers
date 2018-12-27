#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define Maxd  987654321
int num = 0;

int city[16][16];
int check[16][1<<16];

int tour(int now, int visit){
  if(visit == (1<<num)-1){
    if(city[now][0] !=0)
      return city[now][0];
    return Maxd;
  }

  int &result = check[now][visit];
  if(result != -1)
    return result;
  result = Maxd;

  for(int next = 0; next < num;next++){
    if(visit &(1<<next)||city[now][next]==0)
        continue;
    result = min(result, city[now][next]+tour(next,visit+(1<<next)));
  }
  return result;
}

int main(){
  cin>>num;
  for(int i = 0; i<num;i++){
    for(int j = 0; j<num; j++){
      cin >> city[i][j];
    }
  }
  memset(check, -1, sizeof(check));
  printf("%d", tour(0,1));

  return 0;
}
