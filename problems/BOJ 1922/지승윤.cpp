#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int computer[1001];
struct edge{
	int w,v1,v2;
	bool operator < (edge b) { return w < b.w; }
};
vector <edge> arr;
int find(int x) {
	if (computer[x] == 0) return x;
	computer[x] = find(computer[x]);
	return computer[x];
}
void merge(int a,int b){
	int x = find(a);
	int y = find(b);
	computer[y] = x;
}

int main() {
	int n, m,v1,v2,w,result=0;
	scanf("%d\n%d", &n, &m);
	while (m--){
		scanf("%d %d %d", &v1, &v2, &w);
		arr.push_back({w,v1,v2});
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) 
		if (find(arr[i].v1) != find(arr[i].v2))	{
			merge(arr[i].v1, arr[i].v2);
			result += arr[i].w;
		}
	printf("%d", result);
}