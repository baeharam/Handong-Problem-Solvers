#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int tc = 0;
	cin>>tc;
	while (tc--) {
		int n = 0; 
		int a = 0;
		cin>>n;
		int s[2][100001];
		for (int r = 0; r < 2; r++)
			for (int c = 1; c <= n; c++)
				cin>>s[r][c];
		s[0][0] = 0;
		s[1][0] = 0;
		for (int c = 2; c <= n; c++) {
			s[0][c] += max(s[1][c-1],s[1][c-2]);
			s[1][c] += max(s[0][c - 1], s[0][c - 2]);
		}
		a = max(s[0][n],s[1][n]);
		cout<<a<<endl;
	}
	return 0;
}