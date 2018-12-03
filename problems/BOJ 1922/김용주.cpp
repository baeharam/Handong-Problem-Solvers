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
	// ��Ʈ�� �ڱ��ڽ��� return
	if (parent[n] == n) return n;
	// ��Ʈ�� �ƴϸ� ��Ʈ�� ã��
	parent[n] = find(parent[n]);
	// ��Ʈ�� ���� return
	return parent[n];
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	
	// ������ �Ǿ������� false �ƴϸ� ���� ����(����). b�� ��Ʈ�� ��.
	if (a == b) return false;
	parent[b] = a;	
	return true;
}

// weight�� �������� �������� sorting�ϱ� ���� �Լ�
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

	// ������ ��� �ڱ��ڽ��� ��Ʈ.
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	// weight�� �������� struct�� sort.
	stable_sort(t + 1, t + M + 1, compare);

	for (int i = 1; i <= M; i++) 
		if (merge(t[i].a, t[i].b))
			result += t[i].weight;
	
	printf("%d", result);

	return 0;
}
