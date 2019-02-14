#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

vector<int> tree;
int n;
pii a[500000];

int query(int node,int value,int s,int e)
{
    // 특정 값이 시작인덱스보다 작다는 것은
    // 해당 노드의 값이 더 큰 숫자들의 개수를 의미하므로 그냥 리턴
    if(value<s) return tree[node];

    // 마지막 인덱스보다 크다는 것은 특정 값보다 다 작은 것이므로 신경쓸 필요 없음
    // 시작인덱스=마지막 인덱스인 경우도 위에서 걸려졌기 때문에 신경 ㄴㄴ
    if(value>e || s==e) return 0;
    return query(node*2,value,s,(s+e)/2)+query(node*2+1,value,(s+e)/2+1,e);
}
 
 
int update(int node,int s, int e, int value)
{
    // 범위를 벗어나는 경우 고려하지 않음
    if(s>value || e<value) return tree[node];
    // 특정 값이 들어갈 곳을 찾았다면 개수를 1로 만들어줌
    if(s==e) return tree[node] = 1;
    return tree[node] = update(node*2,s,(s+e)/2,value)+update(node*2+1,(s+e)/2+1,e,value);
}

// pair를 두 번째 값 기준으로 정렬하기 위함
bool cmp(pii a1, pii a2){
    return a1.second<a2.second;
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }

    sort(a,a+n);
    for(int i=0; i<n; i++) a[i].first = i;
    sort(a,a+n,cmp);

    tree.resize(4*n);

    for(int i=0; i<n; i++){
        int ans = query(1,a[i].first,0,n-1);
        printf("%d\n",ans+1);
        update(1,0,n-1,a[i].first);
    }

    return 0;
}