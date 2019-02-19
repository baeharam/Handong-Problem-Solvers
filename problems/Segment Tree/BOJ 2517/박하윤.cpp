#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
 
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
 
#define MOD 1000000007
#define INF 0x7fffffff
#define MAX_SIZE (int)1e6
 
using namespace std;
pii arr[(int)5e5];  //실력, 위치
 
int update(vi &tree, int node, int value, int start, int end) {
    if (value < start || end < value) return tree[node];    // 범위 밖 => 바로 리턴
    else if (start == end) return tree[node] = 1; // 시작과 끝이 같다 => 내가 찾는 선수이다 => 1 리턴
 
    int mid = (start + end) / 2;
    return tree[node] = update(tree, node * 2, value, start, mid) + update(tree, node * 2 + 1, value, mid + 1, end);
}
 
int query(vi &tree, int node, int value, int start, int end) {
    if (value < start) return tree[node]; 
    else if (end < value || start == end) return 0;
    
    int mid = (start + end) / 2;
    return query(tree, node * 2, value, start, mid) + query(tree, node * 2 + 1, value, mid + 1, end);
}
 // 재귀함수를 통해 모든 선수의 순위 update

bool cmp(const pii &a, pii &b) {
    return a.second < b.second; // 두번째에 담긴 배열 비교 => 후에 sort에서의 기준 
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);    
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;    // 실력
        arr[i].second = i;      // 위치
    }
 
    sort(arr, arr + n);     // 실력을 상대적으로 배치 
 
    for (int i = 0; i < n; i++) arr[i].first = i;
 
    sort(arr, arr + n, cmp);    // 위치(현 순위)를 상대적으로 배치 
 
    vi tree(1 << ((int)ceil(log2(n)) + 1)); // 구간에 데이터가 몇 개 있는지를 파악하는 트리
 
    for (int i = 0; i < n; i++) {
        cout << 1 + query(tree, 1, arr[i].first, 0, n - 1) << '\n';
        update(tree, 1, arr[i].first, 0, n - 1);
    }
    return 0;
}