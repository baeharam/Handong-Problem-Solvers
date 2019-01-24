#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct edge{
    int v1;
    int v2;
    int weight;

    bool operator>(const edge& e) const{
        return weight>e.weight;
    }
};

priority_queue<edge,vector<edge>,greater<edge> > pq;
int n,m,a,b,c,ans;
int p[100001],r[100001];

int find(int v){
    if(p[v]==v) return v;
    else return p[v] = find(p[v]);
}

void uni(int v1, int v2){
    int p1 = find(v1);
    int p2 = find(v2);

    if(r[p1]<r[p2]) p[p1] = p2;
    else if(r[p1]>r[p2]) p[p2] = p1;
    else if(r[p1]==r[p2]){
        r[p1]++;
        p[p2] = p1;
    }
}

int main(void)
{
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        pq.push({a,b,c});
    }

    for(int i=1; i<=n; i++){
        p[i] = i;
        r[i] = 1;
    }

    int max = 0;
    while(!pq.empty()){
        edge e = pq.top(); pq.pop();
        int v1 = e.v1, v2 = e.v2;
        if(find(v1)!=find(v2)){
            ans += e.weight;
            if(max<e.weight) max = e.weight;
            uni(v1,v2);
        }
    }

    printf("%d",ans-max);

    return 0;
}