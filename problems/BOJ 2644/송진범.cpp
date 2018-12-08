#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, x, y, m;
	cin >> n >> x >> y >> m; //값 입력

	int a, b;
	vector<int> family[101]; //100이지만 q의 탐색을 위해 1증가
	vector<int> visited(101, 0);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		family[a].push_back(b);
		family[b].push_back(a);
	}  //양방향으로 만들어줌

	queue <int> q;  //BFS는 Q를 사용함
	q.push(x); //시작점에 x넣어줌
	while (!q.empty()) {
		int now = q.front();
		q.pop(); //하나 호출 후 탐색
		if (x == y){ //같은 점일시 break;
			break;
    }
		for (int i = 0; i < family[now].size(); i++){
			if (!visited[family[now][i]]){
				visited[family[now][i]] = visited[now] + 1;  //거리를 1씩 증가
				q.push(family[now][i]);  //연결된 노드 집어넣음
			}
		}
	}

  cout << (visited[y] == 0 ? -1 : visited[y]) << endl; //거리 출력
  return 0;
}
-
