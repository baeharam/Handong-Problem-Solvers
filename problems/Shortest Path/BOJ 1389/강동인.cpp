#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;


vector <int> a[101];
int c[101], d[101], ans[101], t = 1000;
int N, M, r1, r2;



void BFS(int p) {

	queue <int> q;
	q.push(p);

	c[p] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < a[x].size(); i++)	{

			int y = a[x][i];
			if (c[y] == 0)	{
					q.push(y);

				c[y] = 1;
				d[y] = d[x] + 1;
			}
		}
	}
}

int main() {

	cin >> N >> M;
	while (M--) {
		cin >> r1 >> r2;
		a[r1].push_back(r2);
		a[r2].push_back(r1);
	}

	for (int i = 1; i <= N; i++) {

		memset(c, 0, sizeof(c));
		memset(d, 0, sizeof(d));

		BFS(i);

		int s = 0;

		for (int j = 1; j <= N; j++)
			s += d[j];

		ans[i] = s;

	}

	for (int i = 1; i <= N; i++)	{
		if (t > ans[i])
			t = ans[i];
	}

	for (int i = 1; i <= N; i++)	{
		if (t == ans[i])	{
			cout << i;
			break;
		}
	}
}
