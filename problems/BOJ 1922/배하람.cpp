#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,ans;
struct edge{
    int v1,v2,w;
    bool operator<(const edge& rhs){
        return w < rhs.w;
    }
};
edge e[100000];
int p[1001],r[1001];

int find(int v){
    if(p[v]==v) return v;
    else return p[v] = find(p[v]);
}

void uni(int v1,int v2){
    v1 = find(v1); v2 = find(v2);
    if(r[v1]<r[v2]) p[v1] = v2;
    else p[v2] = v1;
    if(r[v1]==r[v2]) r[v1]++;
}

int main(void)
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        p[i] = i;
        r[i] = 0;
    }
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&e[i].v1,&e[i].v2,&e[i].w);
    
    sort(e,e+m);

    for(int i=0; i<m; i++){
        if(find(e[i].v1)!=find(e[i].v2)){
            ans += e[i].w;
            uni(e[i].v1,e[i].v2);
        }
    }
    printf("%d",ans);
    return 0;
}