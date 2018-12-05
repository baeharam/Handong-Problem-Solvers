// 9205
#include<iostream>
#include<vector>
using namespace std;
 
int t = 0, n = 0;
vector<pair<int, int> > v;
vector<vector<int> > map;
 
int abs(int n){
    return ((n < 0) ? -n : n);  //절댓값
}
 
bool distance(int x1, int y1, int x2, int y2){
    return ((abs(x1 - x2) + abs(y1 - y2)) <= 1000 ? true : false); // 1000 이상 or 이하?
}
 
int main(void){
    cin >> t;       // case 갯수
    while (t--){
        cin >> n;           // 편의점 갯수
        v = vector<pair<int, int> > (n + 2, home_pair(0, 0));       
        map = vector<vector<int> >(n + 2, vector<int>(n + 2, 0));   // ?
 
        for (int i = 0; i < n + 2; i++)
            cin >> v[i].first >> v[i].second;       // 좌표 입력
 
        for (int i = 0; i < n + 2; i++)
            for (int j = 0; j < n + 2; j++)
                if (distance(v[i].first, v[i].second, v[j].first, v[j].second))
                    map[i][j] = map[j][i] = 1;
 
        for (int k = 0; k < n + 2; k++)
            for (int i = 0; i < n + 1; i++)
                for (int j = 1; j < n + 2; j++)
                    if (map[i][k] && map[k][j])
                        map[i][j] = map[j][i] = 1;      
 
        cout << (map[0][n + 1] ? "happy" : "sad") << endl;  
    }
    return 0;
}