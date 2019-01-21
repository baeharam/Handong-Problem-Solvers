//BOJ1931
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Meeting{int s, e;};
int N;
Meeting m[100001];

//끝나는 시간이 동일하면 시작시간이 빠른거
bool cmp(Meeting a, Meeting b){
    if(a.e == b.e) return a.s < b.s;
    return a.e < b.e;
}

int main(void)
{
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        scanf("%d%d", &m[i].s,&m[i].e);

    sort(m, m+N, cmp);
    int ans = 0;
    int end = -1;
    for(int i = 0; i < N; i++){
        if(m[i].s >= end){
            end = m[i].e;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}