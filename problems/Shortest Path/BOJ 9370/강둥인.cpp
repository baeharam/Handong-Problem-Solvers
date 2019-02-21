#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 100000000
using namespace std;

struct Vertex{
    int dist = INF, idx;
    vector<int> post;
    vector< pair<int, int> > next;
    bool operator < (const Vertex &v) const {
        return dist > v.dist;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int n, m, t, s, g, h;
        cin >> n >> m >> t >> s >> g >> h;
        Vertex vertex[n+1];

        for(int i = 1; i <= n; i++) {
            vertex[i].idx = i;
        }

        vector<int> target;
        while(m--) {
            int a, b, d;
            cin >> a >> b >> d;
            d *= 2;
            if((a == g && b == h)||(a == h && b == g))
              d -= 1;

            vertex[a].next.push_back(make_pair(d, b));
            vertex[b].next.push_back(make_pair(d, a));
        }

        while(t--) {
            int ta;
            cin >> ta;
            target.push_back(ta);
        }

        priority_queue<Vertex> pq;
        vertex[s].dist = 0;
        pq.push(vertex[s]);

        while(!pq.empty()) {
            Vertex curVertex = pq.top();
            pq.pop();
            for(pair<int, int> pa : curVertex.next){
                int w = pa.first;
                int nIdx = pa.second;
                if(vertex[nIdx].dist > curVertex.dist + w) {
                    vertex[nIdx].dist = curVertex.dist + w;
                    pq.push(vertex[nIdx]);
                }
            }
        }

        sort(target.begin(), target.end());
        for(int tIdx : target) {
            if(vertex[tIdx].dist % 2 != 0){
                cout << tIdx << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}
