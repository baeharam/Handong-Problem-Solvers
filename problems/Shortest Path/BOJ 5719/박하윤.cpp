#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, S, D, U, V, P; // #of places, #of roads, starting point, end point, P = U에서 V까지의 거리 
int dist[502];
int a[502][502];    // a[startpoint][endpoint]

void dijkstra(){
    memset(dist, -1, sizeof(dist)); // dist array 모두 -1로 채움
    priority_queue<pair<int, int> > PQ; // int형 변수 2개 저장가능한 페어를 PQ형태로
    PQ.push({ 0, S });   // 0과 시작점 S를 넣음
    while (PQ.size()) {    // PQ size가 0이 될때까지 반복
        int curr = PQ.top().second;
        int cost = -PQ.top().first; // -가 붙는 이유는..?
        PQ.pop();   // 밖으로 빼기
        if (dist[curr] != -1) continue; // current distance가 -1이 아닐경우 계속 continue
        dist[curr] = cost;// dist[PQ.top().second] = -PQ.top().first => 현위치의 거리에 비용, 즉 PQ의 첫번째 int중 가장 큰 값 
        for (int i = 0; i < N; i++) {
            if (a[curr][i] == -1) continue; // 현위치를 제외한 나머지와의 거리는 -1
            if (dist[i] != -1)continue;     // 인접한 장소들과의 거리는 -1이 아님
            PQ.push({ -cost - a[curr][i],i }); // ?
        }
    }
}
void eraseEdge() {  // 이 함수관련 이해 아직 부족..
    queue<int> QU;
    QU.push(D); // endpoint를 QU에 push
    while (QU.size()) {
        int cx = QU.front();
        QU.pop();
        for (int i = 0; i < N; i++) {
            if (dist[cx] == dist[i] + a[i][cx] && a[i][cx] != -1) {     
                a[i][cx] = -1;
                QU.push(i);
            }    
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    while(N != 0 && M != 0){
        scanf("%d %d", &S, &D);
        memset(a, -1, sizeof(a));

        for(int i = 0; i < M; i++){
            scanf("%d %d %d", &U, &V, &P); 
            a[U][V] = P;    // u에서 v까지의 거리 = P 를 array 로 나타냄
        }
        dijkstra();
        eraseEdge();
        dijkstra();
        printf("%d\n", dist[D]);
        scanf("%d %d", &N, &M);
    }
    return 0;
}
//출처: http://jason9319.tistory.com/12 [ACM-ICPC 상 탈 사람]