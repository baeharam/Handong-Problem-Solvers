#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class network{
	public:
	int node1;
	int node2;
	int weight;
};

bool cmp(const network &a, const network &b){
	return a.weight < b.weight;
}

void merge(int &)

int main(){
	int comp, line, i;
	scanf("%d", &comp);
	scanf("%d", &line);
	vector<int> parent(comp+1);
	vector<network> a(line); //total # of lines
	for(i=0; i<line; i++){
		scanf("%d %d %d", &a[i].node1,&a[i].node2,&a[i].weight);
	}
	stable_sort(a.begin(), a.end(), cmp);
	for(i=1; i<comp+1; i++){
		parent[i] = i;
	}
	int cnt=0,t_w=0;
	for(i=0; i<line && parent.size() != 1;i++){
		if(parent[a[i].node1] == parent[a[i].node2]) continue;
		else{
			merge(parent[a[i].node1], parent[a[i].node2]);
			t_w += a[i].weight;
		}
	}
	printf("%d", t_w);
}
