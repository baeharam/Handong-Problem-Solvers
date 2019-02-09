#include <cstdio>

int n,m,s,e,ans;
int a[10001];

int main(void)
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }

    for(int i=2; i<=n; i++){
        a[i] += a[i-1];
    }

    e = 1;
    while(e<=n){
        if(a[e]-a[s]<m) e++;
        else if(a[e]-a[s]>=m){
            if(a[e]-a[s]==m) ans++;
            s++;
        }
    }

    printf("%d",ans);
    return 0;
}