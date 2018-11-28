#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int tc,n;
int a[3][100001],dp[100001][4];

int main(void)
{
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[1][i]);
        for(int i=1; i<=n; i++) scanf("%d",&a[2][i]);

        dp[1][1] = a[1][1];
        dp[1][2] = a[2][1];
        dp[1][3] = 0;

        for(int i=2; i<=n; i++){
            dp[i][1] = max(dp[i-1][2],dp[i-1][3]) + a[1][i];
            dp[i][2] = max(dp[i-1][1],dp[i-1][3]) + a[2][i];
            dp[i][3] = max(dp[i-1][1],dp[i-1][2]);
        }

        printf("%d\n",max(dp[n][1],max(dp[n][2],dp[n][3])));
    }
    return 0;
}