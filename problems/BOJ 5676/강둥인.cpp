#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

vector<int> tree;
vector<int> data;
int n, m;

int get_number(int num){
	if (num > 0)
		return 1;

	if (num < 0)
		return -1;

	return 0;
}
int get_idx(){
	int idx = 1;
	while (idx < n)
		idx *= 2;
	return idx;
}

void makeTree(){
	int idx = get_idx();
	tree.clear();
	tree.resize(idx * 2 + 1, 1);
	for (int i = idx; i < idx + n; i++){
		tree[i] = data[i - idx];
	}
	idx /= 2;
	while (idx){
		for (int i = idx; i < idx * 2; i++){
			tree[i] = tree[i * 2] * tree[i * 2 + 1];
		}
		idx /= 2;
	}
}

void update(int pos, int num){
	int idx = get_idx() - 1 + pos;
	tree[idx] = num;
	idx /= 2;
	while (idx){
		tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
		idx /= 2;
	}
}

char query(int left, int right){
	left += (get_idx() - 1);
	right += (get_idx() - 1);

	int num = 1;
	while (left <= right){
		if (left % 2 == 1)
			num *= tree[left++];

		if (right % 2 == 0)
			num *= tree[right--];
		left /= 2;
		right /= 2;
	}
	if (num > 0)

		return '+';
	if (num < 0)

		return '-';
	return '0';
}

int main() {
	while (cin >> n >> m){
		data.clear();
		for (int i = 0; i < n; i++){
			int t1;
			cin >> t1;
			data.push_back(get_number(t1));
		}
		makeTree();
		for (int i = 0; i < m; i++){
			char q;
			int pos, num;
			getchar();

			scanf("%c %d %d", &q, &pos, &num);
			if (q == 'C'){
				update(pos, get_number(num));
			}
			if (q == 'P'){
				cout << query(pos, num);
			}
		}
		cout << endl;
	}

}
