#include <iostream>
#include <queue>

using namespace std;

int main() {
	int people, p1, p2, relation, arr[101][101], d[101], answer;
	scanf("%d", &people);
	scanf("%d %d", &p1, &p2);
	scanf("%d", &relation);
	for(int i=0; i<relation; i++){
		int x = 0, y = 0;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	queue<int> q;
	q.push(p1);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=1; i<=people; i++){
			if(arr[now][i] ==0 || d[i] != 0) continue;
			d[i] = d[now] + 1;
			q.push(i);
		}
	}
	answer = d[p2] == 0? -1 : d[p2];
	printf("%d", answer);
}
