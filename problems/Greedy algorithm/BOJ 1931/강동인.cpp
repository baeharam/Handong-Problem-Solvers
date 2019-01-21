#include <iostream>
#include <algorithm>
#include <deque>
#include <utility>

using namespace std;

int n;
int cnt = 0;
deque <pair<int, int>> v;


int main() {

	cin >> n;
	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		v.push_back(pair<int, int>(b, a));
	}

	sort(v.begin(), v.end());

	int firstly = 0;
	while (!v.empty()) {
		int start = v.front().second;
		int end = v.front().first;

		if (firstly <= start) {
			firstly = end;
			cnt++;
		}

		v.pop_front();
	}
	cout << cnt << endl;

	return 0;

}
