//Baekjoon 1992 Odsn
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int a, b, weight;
}Tree;

Tree t[100001];
int parent[1001];

int N, M, result;


int find(int n) {
	// 루트면 자기자신을 return
	if (parent[n] == n) return n;
	// 루트가 아니면 루트를 찾음
	parent[n] = find(parent[n]);
	// 루트의 값을 return
	return parent[n];
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	// 연결이 되어있으면 false 아니면 둘을 결합(연결). b가 루트가 됨.
	if (a == b) return false;
	parent[b] = a;	
	return true;
}

// weight를 기준으로 오름차순 sorting하기 위한 함수
bool compare(const Tree &t1,const Tree &t2) {
	if (t1.weight < t2.weight)
		return true;
	else
		return false;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= M; i++) 
		scanf("%d %d %d", &t[i].a, &t[i].b, &t[i].weight);

	// 시작은 모두 자기자신이 루트.
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	// weight를 기준으로 struct를 sort.
	stable_sort(t + 1, t + M + 1, compare);

	for (int i = 1; i <= M; i++) 
		if (merge(t[i].a, t[i].b))
			result += t[i].weight;
	
	printf("%d", result);

	return 0;
}
