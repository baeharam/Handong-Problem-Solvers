#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>

#define inf 99999

using namespace std;

typedef pair<int, int> P;

map<P, int> maps;

double getDist(P a, P b) {
    int x = a.first - b.first;
    int y = a.second - b.second;

    return (double)(x * x + y * y);
}

int main() {
    int n;
    cin >> n;

    vector<P> coordinate;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        coordinate.push_back({ x,y });
    }

    sort(coordinate.begin(), coordinate.end());

    maps[{coordinate[0].second, coordinate[0].first}] = 1;
    maps[{coordinate[1].second, coordinate[1].first}] = 1;

    double ans = getDist(coordinate[0], coordinate[1]);

    int last = 0;

    for (int i = 2; i < n; i++) {
        while (last < i)
        {
            // i > last
            int dx = coordinate[i].first - coordinate[last].first;

            if (dx * dx <= ans)
                break;

            maps.erase({ coordinate[last].second, coordinate[last].first });
            last++;
        }

        int limit = sqrt(ans);

        auto lo = maps.lower_bound({ coordinate[i].second - limit, -inf });
        auto up = maps.upper_bound({ coordinate[i].second + limit,  inf });


        for (auto it = lo; it != up; it++)
            ans = min(ans, getDist({ it->first.second, it->first.first }, coordinate[i]));

        maps[{coordinate[i].second, coordinate[i].first}] = 1;
    }

    printf("%d", (int)ans);
    return 0;
}
