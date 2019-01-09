#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int> > d;
int N, M;
void floyd (){
  for (int k = 1; k <= N; k++)
  {
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
      }
    }
  }
}
int main (){
  scanf("%d%d", &N, &M);
  d.resize(N + 1);
  for (int i = 1; i <= N; i++)
  {
    d[i].resize(N + 1);
    for (int j = 1; j <= N; j++)
    {
      d[i][j] = 1912412;
    }
    d[i][i] = 0;
  }
  for (int i = 0; i < M; i++)
  {
    int a, b;
    scanf("%d%d", &a ,&b);
    d[b][a] = d[a][b] = 1;
  }
  floyd();
  int result = 135812375;
  int idx = 0;
  for (int i = 1; i <= N; i++)
  {
    int temp = 0;
    for (int j = 1; j <= N; j++)
    {
      if (d[i][j] == 1912412)
      continue; temp += d[i][j];
    }

    if (result > temp) 
    result = temp,

    idx = i;
  }
  printf("%d", idx);
}
