#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, m, a, b, visited[101];
vector<int> adj[101];

int main()
{
    scanf("%d %d  %d  %d", &n, &a, &b, &m);

    for(int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d",&x, &y);
        adj[y].push_back(x);
        adj[x].push_back(y);
    }

    queue<int> Q;
    Q.push(a);
    while(!Q.empty()){
        int cur = Q.front();   
        Q.pop();
        for(int &next: adj[cur]){
            if(! visited[next]){
                visited[next] = visited[cur] + 1;
                Q.push(next);
            }
        }
    }
    if(!visited[b]) printf("-1\n");
    else printf("%d", visited[b]);
    return 0;
}