#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define lengt 1000001LL
bool prime[lengt];

int Eratos(int m, int n){
  int era=0;
  for(int i = 1; i<=n;i++)
    prime[i]=true;

  for(int i = 2; i*i <=n;i++){
      for(int j = i*i;j<=n;j+=i){
        if(prime[i])
          prime[j]=false;
    }
  }

  for(int i = m; i<=n; i++){
    if(prime[i])
      era++;
  }
  return era;
}

int square(int s, int e){
  int result = 0;
  for(int i = s; i<=e;i++){
      if(prime[i])
        if(i%4==1)
          result++;
  }
  return result;
}

int main(){
  while(1){
    int L, U,x, y = 0;
    cin>>L>>U;
    if(L==-1&&U==-1)
      break;
    x = Eratos(L, U);
    y = square(L, U);
    printf("%d %d %d %d\n",L,U,x, y);
  }
}
