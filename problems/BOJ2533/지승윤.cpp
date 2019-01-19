#include <bits/stdc++.h>
using namespace std;
int ans;
vector<int> a[1000001];
int v[1000001];
bool dfs(int n){
	v[n] = 1;
	int f = 0;
	for (auto ne : a[n]){
		if (v[ne])continue;
		if(!dfs(ne)) f=1;
	}	
	if (f) {
		ans++;
		return 1;
	}
	else return 0;
}
int n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin>>n;
	for (int i = 0; i < n - 1; i++){
		int s, e;
		cin>>s>>e;
		s--; e--;
		a[s].push_back(e);
		a[e].push_back(s);
	}
	dfs(0);
	cout<<ans;
}