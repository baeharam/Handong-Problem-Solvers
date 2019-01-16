#include<algorithm>
#include<iostream>
#define N_ 100001   
#define INT 0x7fff0000

using namespace std; 

int seg[N_ * 4], a[N_], t, n, m, k;

void init(int node, int x, int y) {
	if (x == y) {
		if (a[x] > 0) seg[node] = 1; 
		else if (a[x] == 0) seg[node] = 0; 
		else if (a[x] < 0)  seg[node] = -1; 
		return; 
	}
	int mid = (x + y) >> 1; 
	init(node << 1, x, mid); 
	init((node << 1) + 1, mid + 1, y); 
	seg[node] = seg[node << 1] * (seg[(node << 1) + 1]); 
	return; 
}

void update(int pos, int val, int node, int x, int y) { 
	if (pos < x || pos > y) return; 
	if (x == y) {
		if (val > 0) seg[node] = 1;
		else if (!val) seg[node] = 0; 
		else if (val < 0) seg[node] = -1; 
		return; 
	}
	int mid = (x + y) >> 1; 
	update(pos, val, node << 1, x, mid); 
	update(pos, val, (node << 1) + 1, mid + 1, y); 
	seg[node] = seg[node << 1] * seg[(node << 1) + 1]; 
	return; 
}

int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || x > hi) return 1; 
	if (lo <= x && y <= hi) return seg[node]; 
	int mid = (x + y) >> 1; 
	int l = query(lo, hi, node << 1, x, mid); 
	int r = query(lo, hi, (node << 1) + 1, mid + 1, y); 
	return l*r; 
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++)
			cin >> a[i]; 

		init(1, 1, n); 
		while (m--) {
			char inp; int x, y; 
			cin >> inp >> x >> y;
			if (inp == 'C') 
				update(x, y, 1, 1, n);
			else if (inp == 'P'){
				int ans = query(x, y, 1, 1, n);
				if (ans == 0)
					cout << '0';
				else if (ans > 0)
					cout << '+';
				else if ( ans < 0)
					cout << '-'; 
			}
		}
		cout << '\n'; 
	}
	return 0; 
}
//출처: [C++]음주 코딩[백준 5676]|작성자 Minerba