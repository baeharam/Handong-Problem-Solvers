//BOJ2637
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 101
int n, m, part[MAX_N][MAX_N], result[MAX_N];
bool visit[MAX_N];
vector<int> df;

void assemble(int x, int amnt){
	for(int i = 1; i <= n; i++){
		int a = amnt * part[x][i];
		if(part[x][i]){
			if(visit[i]) result[i] += a;
			else assemble(i, a);
		}
	}
	return;
}

void checkPart(){
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(part[i][j] != 0) break;
		}
		if(j == n+1){
			df.push_back(i);
			visit[i] = true;
		}
	}
	return;
}

int main(){
	scanf("%d %d", &n, &m);
	int x, y, k;

	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &x, &y, &k);
		part[x][y] = k;
	}

	checkPart();
	assemble(n, 1);
	for(int i = 0; i < df.size(); i++){
		printf("%d %d\n", df[i], result[df[i]]);
	}
	return 0;
}