#include <iostream>
#include <algorithm>
using namespace std;

int p[1000];

int find(int x){            // 각 union의 루트 찾기
    if(p[x] < 0) return x;
    return p[x] = find(p[x]); 
}
int merge(int x, int y){        // 루트 다른 union들 합치기
    x = find(x);
    y = find(y);
    if(x == y) return false;
    p[y] = x;
    return true;
}
struct Edge{
    int u, v, w;
    Edge(): Edge(-1, -1, 0){}
    Edge(int u1, int v1, int w1): u(u1), v(v1), w(w1){}
    bool operator < (const Edge& O)const { return w < O.w; }     // 오버로딩 --> 연산자에 대해 그 의미를 다시 부여하는 것/ // (Edge < 0) 의미..?
};

int main()
{
    int N, M;
    
    cin >> N >> M;
    Edge e[100000];     // 구조체 선언

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = Edge(a-1, b-1, c);      
    }
    sort(e, e + M);

    int result = 0, cnt = 0;
    fill(p, p + N, -1);         // p 값 -1로 초기화 p~p+N을 -1로 채우는 함수 fill (memset은..?)
    for(int i = 0;  ; i++){
        if(merge(e[i].u, e[i].v)){
            result += e[i].w;
            if(++cnt == N - 1) break;
        }
    }
    cout << result;
}