#include <cstdio>
#include <algorithm>
#define MAX_SIZE 200000


 //http://donggod.tistory.com/24

 
int pos[MAX_SIZE];

int main()
{
    int n, c;
    scanf("%d %d", &n, &c);

    for(int i = 0; i < n; i++) scanf("%d", pos + i);

    std::sort(pos, pos + n);

    int left = 1, right = pos[n - 1] - pos[0];
    int ret;

    while(left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = 1;
        int start = pos[0];

        for(int i = 1; i < n; i++)
        {
            if(pos[i] - start >= mid)
            {
                cnt++;
                start = pos[i];
            }
        }

        if(cnt >= c)
        {
            ret = mid;
            left = mid + 1;
        }
        else right = mid - 1;

    }

    printf("%d\n", ret);


    return 0;
}
