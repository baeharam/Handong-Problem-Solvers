// baekjoon 2529 yechan
#include <cstdio>
#include <stack>
using namespace std;

char a[15];
int k, n;
stack<int> st;

void f() { while(!st.empty()) printf("%d", st.top()), st.pop(); }

void find_max() {
	n = 9;
	st.push(n--);
	for (int i=0; i<k; i++) {
		scanf("%s", &a[i]);
		if (a[i]=='>') f();
		st.push(n--);
	}
	f();	
}

void find_min() {
	n = 0;
	st.push(n++);
	for (int i=0; i<k; i++) {
		if (a[i]=='<') f();
		st.push(n++);
	}
	f();
}

int main() {
	scanf("%d", &k);
	find_max();
	puts("");
	find_min();
	return 0;
}