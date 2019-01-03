#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
 
#define inf 100000000
using namespace std;

typedef pair<int, int> pii;
 
map<pii, int> mp;
 
double getDist(pii a, pii b)
{
    int x = a.first - b.first;
    int y = a.second - b.second;
 
    return (double)(x*x + y*y); // 공식
}
 
int main()
{
    int n;
    scanf("%d", &n);
 
    vector<pii> vc;
 
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
 
        vc.push_back({ x,y });      // 배열이 아니라 벡터로 바로 바로 push 
    }
 
    sort(vc.begin(), vc.end());     // x에 대해 정렬 순서대로 
 
    // 처음 두 값 map에 추가 (y, x 순서)
    mp[{vc[0].second, vc[0].first}] = 1;
    mp[{vc[1].second, vc[1].first}] = 1;
 
    double ans = getDist(vc[0], vc[1]);    // 최솟값 초기화 ,,,;;
 
    int last = 0;
    for (int i = 2; i < n; i++)
    {
        // while문은 최솟값보다 x간의 거리가 더 큰 것을 제거하는 과정
        while (last < i)
        {
            int dx = vc[i].first - vc[last].first;
 
            if (dx * dx <= ans)
                break;          // 최솟값이 더 크거나 같으면 break
 
            mp.erase({ vc[last].second, vc[last].first });  // 최솟값 보다 더 크면 erase
        }

        int dist = sqrt(ans);   // ans의 실제 거리
 
        // y좌표에서 답일 수 있는 영역 설정 +/- dist
        auto lo = mp.lower_bound({ vc[i].second - dist, -inf });
        auto up = mp.upper_bound({ vc[i].second + dist,  inf });
 
        // 그 영역 내에서 최솟값 search
        for (auto it = lo; it != up; it++)
            ans = min(ans, getDist({ it->first.second, it->first.first }, vc[i]));

        mp[{vc[i].second, vc[i].first}] = 1;
    }
    printf("%d", (int)ans);
    return 0;
}