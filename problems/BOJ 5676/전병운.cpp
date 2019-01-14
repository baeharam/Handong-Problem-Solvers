#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <utility>
#include <functional>
#define MAX 100005
#define MOD 1000000007
#pragma warning(disable:4996)
using namespace std;

int n,m,a,b,map[MAX*4],ans;

int segtree(int cur,int val, int left, int right, int ldest,int rdest)
{
    if(left==ldest&&right==rdest)
    {
        map[cur]=val;
        return map[cur];
    }
    if(right<ldest||rdest<left)
        return map[cur];
    int mid=(left+right)/2;
    map[cur]=segtree(cur*2,val,left,mid,ldest,rdest)*segtree(cur*2+1,val,mid+1,right,ldest,rdest);
    return map[cur];
}
// 세그먼트 트리의 update를 하는 과정 하나씩 트리를 완성해간다.

void result(int cur,int left, int right, int ldest,int rdest)
{
    if(ldest<=left&&right<=rdest)
    {
        ans*=map[cur];
        return;
    }
    if(right<ldest||rdest<left)
        return;

    int mid=(left+right)/2;
    result(cur*2,left,mid,ldest,rdest);
    result(cur*2+1,mid+1,right,ldest,rdest);
}
// 정답을 출력하기위해 계산을한다.

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        fill_n(&map[0],MAX*4,1);
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(tmp>0)
                segtree(1,1,1,n,i,i);
            else if(tmp<0)
                segtree(1,-1,1,n,i,i);
            else
                segtree(1,0,1,n,i,i);
            // 정답의 오버플로우 방지를 위해서 0,1,-1 이용한다.
        }
        for(int i=0;i<m;i++)
        {
            ans=1;
            char tmp;
            scanf(" %c %d %d",&tmp,&a,&b);
            if(tmp=='C')
            {
                if(b>0)
                    segtree(1,1,1,n,a,a);
                else if(b<0)
                    segtree(1,-1,1,n,a,a);
                else
                    segtree(1,0,1,n,a,a);
                // 정답의 오버플로우 방지를 위해서 0,1,-1 이용한다.
            }
            else if(tmp )
            {
                result(1,1,n,a,b);
                if(ans==0)
                    printf("0");
                else if(ans>0)
                    printf("+");
                else
                    printf("-");
            }
        }
        printf("\n");
    }
}
