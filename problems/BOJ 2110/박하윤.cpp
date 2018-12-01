#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 2000000

int N, C;
int home[MAX];

bool check(int dist){
    int cnt = 1;
    int prev = home[0];

    for(int i = 1; i < N; i++){ 
        if(home[i] - prev >= dist){ // 거리가 사이 간격들보다 작거나 같아야함
            cnt++;
            prev = home[i];
        }
    }
    if(cnt >= C)    // 공유기의 갯수
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> C;

    for(int i = 0; i < N; i++)
        cin >> home[i];
    sort(home, home + N); //분류(오름차순)

    int left = 1;                     // 최단거리
    int right = home[N - 1] - home[0]; // 최대거리
    int result = 0;

    while(left <= right){   // 이분 탐색
        int mid = (left + right) / 2;
        if(check(mid)){
            result = max(result, mid);  // 최대거리
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << result << "\n";
    return 0;
}