#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long lld;

struct P
{
    int x, y;
    P(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    bool operator < (const P& rhs) const
    {
        if(y != rhs.y) return y < rhs.y;
        return x < rhs.x;
    }
};

int sqrt2(int cur)
{
    int l = 0;
    int r = cur;

    while(l < r)
    {
        lld m = (1LL * l + r + 1) / 2;
        if(m * m > cur)
        {
            r = m - 1;
        }
        else
        {
            l = m;
        }
    }
    return l;
}

int dist(const P& a, const P& b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main()
{
    int n;
    cin >> n;
    vector<P> v(n);
    for(int i = 0;i < n; ++i)
    {
        cin >> v[i].x >> v[i].y;
    }

    sort(v.begin(), v.end(), [&](const P a, const P b) -> bool{
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    set<P> s;
    s.insert(v[0]);
    s.insert(v[1]);
    int cur = 0;
    int ans = dist(v[0], v[1]);
    for(int i = 2; i < n; ++i)
    {
        int cx = v[i].x;
        int cy = v[i].y;
        int d = sqrt2(ans);

        while(cur < i)
        {
            if(v[i].x - v[cur].x > d){
                s.erase(v[cur]);
                ++cur;
            }
            else
            {
                break;
            }
        }

        auto lb = s.lower_bound(P(-2e9, v[i].y - d));
        auto rb = s.upper_bound(P(2e9, v[i].y + d));
        for(auto it = lb; it != rb; ++it){
            ans=min(ans, dist(v[i], *it));
        }
        s.insert(v[i]);
    }
    cout << ans << '';
}
