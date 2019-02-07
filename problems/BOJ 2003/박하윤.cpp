#include <cstdio>
using namespace std;

int main(){
    int n, m, a[10001], sum, result, s, e;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
        
    s = 0; e = 0; result = 0;
    while(1){
        if(sum >= m) sum -= a[s++];
        else if(e == n) break;
        else sum += a[e++];
        if(sum == m) result++;
    }
    printf("%d\n", result);
    return 0;
}
/*#include <cstdio>

int main(){
    int n, m, a[10001], sum, result;
    int s;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
        sum += a[i];
        while(sum > m)
            sum -= a[s++];
        if(sum == m)
            result++;
    }
    
    printf("%d\n", result);
    return 0;
}*/