#include <cstdio>
#include <cstring>
using namespace std;

int n;
int visit[10],r_max[10],r_min[10];
char s[9];

bool dfs_max(int v, int index)
{
    r_max[index] = v;
    if(index==n) return true;
    visit[v]=1;
    if(s[index]=='<') {
        for(int i=9; i>=v; i--) 
            if(!visit[i] && dfs_max(i,index+1)) return true;
    }
    if(s[index]=='>') {
        for(int i=v-1; i>=0; i--) 
            if(!visit[i] && dfs_max(i,index+1)) return true;
    }
    visit[v]=0;
    return false;
}

bool dfs_min(int v, int index)
{
    r_min[index] = v;
    if(index==n) return true;
    visit[v]=1;
    if(s[index]=='<') {
        for(int i=v; i<=9; i++) 
            if(!visit[i] && dfs_min(i,index+1)) return true;
    }
    if(s[index]=='>') {
        for(int i=0; i<=v-1; i++) 
            if(!visit[i] && dfs_min(i,index+1)) return true;;
    }
    visit[v]=0;
    return false;
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf(" %c",&s[i]);

    for(int i=9,j=0; i>=0,j<=9; i--) {
        memset(&visit,0,sizeof(visit));
        if(dfs_max(i,0)) break;
    }

    for(int i=0; i<=9; i++) {
        memset(&visit,0,sizeof(visit));
        if(dfs_min(i,0)) break;
    }

    for(int i=0; i<n+1; i++) printf("%d",r_max[i]);
    printf("\n");
    for(int i=0; i<n+1; i++) printf("%d",r_min[i]);

    return 0;
}