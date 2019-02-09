#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct box{
    int begin;
    int end;
    int interval;
};

vector<box> boxes;
int n,k,d,a,b,c,l,r,m,mid,ans;
long long num;

int main(void)
{
    scanf("%d%d%d",&n,&k,&d);
    for(int i=0; i<k; i++){
        scanf("%d%d%d",&a,&b,&c);  
        boxes.push_back({a,b,c});
    }

    l=1,r=n,m=2e9;
    while(l<=r){
        mid = (l+r)/2;
        num = 0LL;
        for(auto box : boxes){
            if(mid<box.begin) continue;
            num += ((mid>box.end?box.end:mid)-box.begin)/box.interval+1;
        }
        if(num<d) l=mid+1;
        else if(num>=d){
            r=mid-1;
            m = min(m,mid);
        }
    }

    for(auto box : boxes){
        if(box.begin<=m)
            ans = max(ans, box.begin+((m-box.begin)/box.interval)*box.interval);
    }

    printf("%d",ans);
    return 0;
}