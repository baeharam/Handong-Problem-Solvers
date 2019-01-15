#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n,k,in1,in2;
char input;

int init(vector<int>& tree, vector<int>& a, int node, int start, int end)
{
    if(start==end) return tree[node] = a[start]==0?0:(a[start]>0?1:-1);
    int left = init(tree,a,node*2,start,(start+end)/2);
    int right = init(tree,a,node*2+1,(start+end)/2+1,end);

    if(!left || !right) return tree[node]=0;
    if((left>0&&right>0)||(left<0&&right<0)) return tree[node]=1;
    else return tree[node]=-1;
}

int mul(vector<int>& tree, vector<int>& a, int node, int start, int end, int left, int right)
{
    if(start>right || end<left) return 1;
    if(start>=left && end<=right) return tree[node];

    return mul(tree,a,node*2,start,(start+end)/2,left,right)*mul(tree,a,node*2+1,(start+end)/2+1,end,left,right);
}

int update(vector<int>& tree, vector<int>& a, int node, int start, int end, int index, int value)
{
    if(index<start || index>end) return tree[node];
    if(start==end) return tree[node] = value==0?0:(value>0?1:-1);
    return tree[node] = update(tree,a,node*2,start,(start+end)/2,index,value)*update(tree,a,node*2+1,(start+end)/2+1,end,index,value);
}

int main(void)
{
    while(scanf("%d%d",&n,&k)!=EOF){
        vector<int> a(n);
        int h = ceil(log2(n));
        vector<int> tree(1<<(h+2));
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        init(tree,a,1,0,n-1);

        while(k--){
            scanf(" %c%d%d",&input,&in1,&in2);
            if(input == 'C') update(tree,a,1,0,n-1,in1-1,in2);
            else if(input == 'P'){
                int ans = mul(tree,a,1,0,n-1,in1-1,in2-1);
                ans==0?printf("0"):(ans>0?printf("+"):printf("-"));
            }
        }
        puts("");
    }
    return 0;
}