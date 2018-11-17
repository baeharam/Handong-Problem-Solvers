#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
bool dist(int x_1, int y_1, int x_2, int y_2){
    return abs(x_1 - x_2) + abs(y_1 - y_2) <= 1000 ? true : false;
}
int main(){
    int tc, n;
    vector<bool> marked;
    vector<pair<int, int>> v;
    cin>>tc;
    while(tc--){
        cin>>n;
        bool possible = false;
        marked = vector<bool>(n+2, false);
        v = vector<pair<int, int>>(n+2, make_pair(0, 0));
        for (int i = 0; i < n + 2; i++)
            cin>>v[i].first>>v[i].second;
        queue<int> q;
        q.push(0);
        marked[0] = true;
        while (!q.empty()){
            int a = q.front();
            q.pop();
            if(a == n+1){
                possible = true;
                break;
            }
            for (int i = 1; i < n + 2; i++){
                if (!marked[i] && dist(v[a].first, v[a].second, v[i].first, v[i].second)){
                    q.push(i);
                    marked[i] = true;
                }
            }
        }
            cout<<(possible ? "happy" : "sad")<<endl;
    }
    return 0;
}
