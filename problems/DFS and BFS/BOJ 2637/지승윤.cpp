#include<bits/stdc++.h>
using namespace std;
int arr[100]={};
vector<pair<int,int>> child[100];
void add(int here, int part){
	if(!child[here].size()){
		arr[here] += part;
		return;
	}
	for(auto &p : child[here])
		add(p.first, part*p.second);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		child[a-1].push_back({b-1,c});
	}
	add(n-1, 1);
	for(int i=0; i<n; ++i)
		if(arr[i]) cout << i+1 << ' ' << arr[i] << '\n';
}