/*#include <cstdio>
using namespace std;

int main(){
    int n, m, a[10001], sum, result, s, e;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
        
    s = 0; e = 0; result = 0; sum = 0;
    while(1){
        if(sum >= m) sum -= a[s++];
        else if(e == n) break;
        else sum += a[e++];
        if(sum == m) result++;
    }
    printf("%d\n", result);
    return 0;
}*/ //. 두가지 방법으로 구현해봄 => 둘다 수정 후 정상적으로 running

#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int n, m, a[10001], sum, result, s;
    scanf("%d %d", &n, &m);

    sum = 0; result = 0, s = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
        sum += a[i];
        while(sum > m && s < n)
            sum -= a[s++];
        if(sum == m)
            result++;
    }
    
    printf("%d\n", result);
    return 0;
}
