//BOJ1655 가운데를 말해요
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int N, s;
priority_queue<int> pq_max;
priority_queue<int, vector<int>, greater<int> > pq_min;

int main(){
	scanf("%d", &N);
	scanf("%d", &s);
	printf("%d\n", s);
	pq_max.push(s);
	for(int i = 1; i < N; i++){
		scanf("%d", &s);
		if(i % 2 == 1){
			pq_max.push(s);
			int a = pq_max.top();
			pq_min.push(a);
			pq_max.pop();
		}
		else /*i%2 == 0*/ {
			pq_min.push(s);
			int a = pq_min.top();
			pq_max.push(a);
			pq_min.pop();
		}
		printf("%d\n", pq_max.top());
	}

	return 0;
}