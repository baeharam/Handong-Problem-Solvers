#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX = 101;

int N, M;
int graph[MAX][MAX];

void kevin(void){
  for(int i = 1l; i<=N; i++){
    for(int j = 1; j<=N;j++){
      for(int k = 1; k<=N;k++){
        if(j==k)
          continue;
        else if (graph[j][i]&&graph[i][k]){
          if(graph[j][k] == 0)
            graph[j][k] = graph[j][i] + graph[i][k];
          else
            graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k]);
        }
      }
    }
  }
}


int main (void){

  cin >> N>> M;
  for(int i = 0; i < M; i++){
    int A, B;
    cin >> A >> B;
    graph[A][B]=graph[B][A] = 1;
  }

  kevin();

  int result = -1;
  int person = 0;

  for(int i = 1; i<=N;i++){
    int sum = 0;
    for(int j = 1; j<=N; j++)
      sum+=graph[i][j];
      if(result == -1||result > sum)
      {
        result = sum;
        person = i;
      }
  }

  cout << person <<endl;

  return 0;
}
