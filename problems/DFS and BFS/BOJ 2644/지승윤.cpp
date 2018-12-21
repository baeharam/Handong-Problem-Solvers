#include <stdio.h>
bool arr[101][101];
bool visit[101];
int num, q1, q2, m;
int answer=0;

void DFS(int parent, int a)
{
	visit[parent] = true;
	if (parent == q2)
	{
		answer = a;
		return;
	}
	for (int i = 1; i <= num; i++)
		if (arr[parent][i] && !visit[i])
			family(i, a + 1);
}

int main(void)
{
	int e1, e2;
	scanf("%d", &num);
	scanf("%d %d", &q1, &q2);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &e1, &e2);
		arr[e1][e2] = arr[e2][e1] = true;
	}
	DFS(q1, answer);

	if (answer)
		printf("%d", answer);
	else
		printf("-1");
}
