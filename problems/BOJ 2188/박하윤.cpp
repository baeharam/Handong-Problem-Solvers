#include <cstdio>
#include <vector>
using namespace std;
#define Max 200
int N, M, A[Max], B[Max];
vector<int> adj[Max];
bool visited[Max];

bool dfs(int a)
{
    visited[a] = true;
    for(int b: adj[a]){
        if(B[b] == -1 || (!visited[B[b]] && dfs(B[b]))) {
            A[a] = b;   // A는 가축
            B[b] = a;   // B는 축사 => 서로 매칭 when 가축이 비어 있거나 매칭되어 있지만 다른 곳과 매칭가능한 경우
            return true;
        }
    }
    return false;
}

int main()
{
    int Si, Mi;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &Si);
        for(int j = 0; j < Si; j++){
            scanf("%d", &Mi);
            adj[i].push_back(Mi-1);
        }
    }
    int match = 0;
    fill(A, A+N, -1); 
    fill(B, B+M, -1);
    for(int i = 0; i < N; i++){
        if(A[i] == -1){
            fill(visited, visited+N, false);
            if(dfs(i)) match++;
        }
    }
    printf("%d", match);
    return 0;
}