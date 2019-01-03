#include <iostream>
using namespace std;
char s[1000001];
int n, p[1000001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 1, j = 0; s[i]; i++) {
		while (j && s[i] != s[j]) 
			j = p[j - 1];
		p[i] = ++j;
	}
	cout<<"1/"<<(n%(n-p[n - 1])?n:(n-p[n - 1]));
}
