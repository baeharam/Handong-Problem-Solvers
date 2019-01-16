#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> a;
int n,s,e,ans,before;

int main(void)
{
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d",&s,&e);
        a.push_back({e,s});
    }

    sort(a.begin(),a.end());
    ans=1;
    before = a[0].first;
    for(int i=1; i<a.size(); i++){
        if(a[i].second>=before){
            before = a[i].first;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}