#include <stdio.h>
#include <algorithm>
#define x first
#define y second
using namespace std;

const int maxN = 100001;

typedef pair<int, int> Time;  // 끝나는 시간끼리 비교 => 끝나는 시간, 시작하는 시간 으로 pair를 잡음
 
Time meeting[maxN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &meeting[i].y, &meeting[i].x);   

    sort(meeting, meeting + n);
    int finish = meeting[0].x; 
    int cnt = 1; 
    for (int i = 1; i < n; i++) {
        if (meeting[i].y >= finish) {
            cnt++;
            finish = meeting[i].x;
        }
    }
    printf("%d", cnt);
    return 0;
}