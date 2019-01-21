#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,e,a;
pair<int,int> p[100000];
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d %d",&p[i].second,&p[i].first);
	sort(p,p+n);
	for(i=0;i<n;i++){
		if(p[i].second>=e){
			a++;
			e=p[i].first;
		}
	}
	printf("%d",a);
}