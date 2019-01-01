#include <cstdio>
using namespace std;
const int Max_N = 1000002;
 
int mo(int a, int b)
{
    return b ? mo(b, a % b) : a; 
}
 
int main()
{
    int N, p[Max_N];
    int j = 0;
    char a[Max_N], b[Max_N*2];

    scanf("%d",&N);
    for(int i = 0; i < N; ++i)  scanf(" %c ",&a[i]);

    for(int i = 0; i < N; ++i){
        scanf(" %c ",&b[i]);
        b[i+N] = b[i];
    }
   
    for(int i = 1; i < N; ++i){ // a[j]와 a[i] 비교
        while(j && a[j] != a[i]) 
            j = p[j-1];
        if(a[j] == a[i])
            p[i] = ++j;
    }

    int cnt = 0;
    j =  0;
    for(int i = 0; i < N + N - 1; ++i){ // a[j]와 b[i] 비교
        while(j && a[j] != b[i]) 
            j = p[j-1];
        if(a[j] == b[i])  ++j;
        if(j == N){
            ++cnt;  
            j = p[j-1];
        }
    }
    int k = mo(cnt, N);
    printf("%d/%d\n",cnt/k, N/k);
}