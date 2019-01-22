#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Edge {

public:
	int cost;
	int v1;
	int v2;
public:

	Edge(int c, int a, int b) {
		cost = c;
		v1 = a;
		v2 = b;
	}
};

bool compare(Edge a, Edge b) {
	if (a.cost != b.cost)
    return a.cost < b.cost;

  else if (a.v1 != b.v1)
    return a.v1 < b.v1;

  else
    return a.v2 < b.v2;
}

vector<Edge> vt;;
int parent[100010];
int n, m, sum;

int find(int n) {

	if (parent[n] == n)
    return n;

  else
    return parent[n] = find(parent[n]);

}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	parent[a] = b;
}

int main(void) {

	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {

		cin >> a >> b >> c;
		vt.push_back(Edge(c, a, b));
	}

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	stable_sort(vt.begin(), vt.end(), compare);

	sum = 0;

	int MAX = 0;
	for (int i = 0; i < vt.size(); i++) {

		int c = vt[i].cost;
		int V1 = vt[i].v1;
		int V2 = vt[i].v2;

		if (find(V1) != find(V2)) {

			Union(V1, V2);
			sum += c;
			MAX = c;
		}
	}

	cout << sum - MAX;
	return 0;
}
