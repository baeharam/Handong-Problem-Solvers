//BOJ1647 Odsn
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001
#define MAX_M 1000001
struct Tree{
	int a, b, w;
};
int N, M, parent[MAX_N];
Tree t[MAX_M];

int find(int n){
	if(parent[n] == -1) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	parent[b] = a;
	return true;
}

bool cmp(Tree t1, Tree t2){
	if(t1.w == t2.w){
		if(t1.a == t2.a)
			return t1.b < t2.b;
		return t1.a < t2.a;
	}
	return t1.w < t2.w;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &t[i].a, &t[i].b, &t[i].w);
	}
	sort(t, t+M, cmp);

	int ans = 0, cnt = 0;
	fill(parent, parent+N, -1);
	for(int i = 0; i < M; i++){
		if(merge(t[i].a, t[i].b)){
			ans += t[i].w;
			cnt++;
			if(cnt == N-2) break;
		}
	}

	printf("%d", ans);
	return 0;
}