#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1000001;


int N;
vector<int> friends[MAX];
vector<int> graphs[MAX];
bool visited[MAX];
int cache[MAX][2]; //노드, earlyAdaptor?


void DFS(int index) {
  visited[index] = true;
  for (int i = 0; i < friends[index].size(); i++)  {
    int next = friends[index][i];
     if (!visited[next]) {
      graphs[index].push_back(next);
      DFS(next);
    }
  }
}


int IsEarly(int index, bool early) {
  int &result = cache[index][early];
  if (result != -1)
    return result;

//본인이 얼리어답터이면 자식은 어떻든 상관없다
  if (early) {
    result = 1; //얼리어답터이므로
    for (int i = 0; i < graphs[index].size(); i++) {
      int next = graphs[index][i];
      result += min(IsEarly(next, true), IsEarly(next, false));
     }
   }

    //본인이 얼리어답터가 아니면 자식은 무조건 얼리어답터여야한다
    else {
      result = 0; //얼리어답터가 아니므로
      for (int i = 0; i < graphs[index].size(); i++) {
        int next = graphs[index][i];
        result += IsEarly(next, true);
      }
    }
    return result;
}

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N - 1; i++) {
    int node1, node2;
    cin >> node1 >> node2;

    friends[node1].push_back(node2);
    friends[node2].push_back(node1);
  }

 memset(cache, -1, sizeof(cache));
 DFS(1);

 //루트가 얼리어답터일 수도 아닐 수도 있으므로
 cout << min(IsEarly(1, false), IsEarly(1, true)) << endl;
 return 0;

}
