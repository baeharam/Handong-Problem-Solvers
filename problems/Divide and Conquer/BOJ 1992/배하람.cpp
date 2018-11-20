#include <cstdio>

int n,a[64][64];
char s[65];

void q(int r1, int c1, int r2, int c2){

    bool same = true;
    int temp = a[r1][c1];
    for(int i=r1; i<=r2; i++){
        for(int j=c1; j<=c2; j++){
            if(temp!=a[i][j]){
                same = false;
                break;
            }
        }
        if(!same) break;
    }
    if(same){
        printf("%d",a[r1][c1]);
        return;
    }

    printf("(");
    q(r1,c1,(r1+r2)/2,(c1+c2)/2);
    q(r1,(c1+c2)/2+1,(r1+r2)/2,c2);
    q((r1+r2)/2+1,c1,r2,(c1+c2)/2);
    q((r1+r2)/2+1,(c1+c2)/2+1,r2,c2);
    printf(")");
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%s",s);
        for(int j=0; j<n; j++) a[i][j] = s[j]-'0';
    }
    q(0,0,n-1,n-1);
    return 0;
}