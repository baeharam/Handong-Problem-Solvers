#include    <cstdio>
#include    <vector>
#include    <algorithm>
#pragma warning (disable : 4996)

struct tree
{
    int rank;
    int none, early;
    std::vector<int> ad_vertex;
};
int q[1111111];
int st[1111111];
int visit[1111111];
tree t[1111111];
int top = 0;
int front = 0, rear = 0;

int main()
{
    int N;
    scanf("%d", &N);
    if (N == 1)
    {
        printf("1");
        return 0;
    }
    int v, u;
    for (int i = 1; i < N; ++i)
    {
        scanf("%d%d", &v, &u);
        t[v].ad_vertex.push_back(u);
        t[u].ad_vertex.push_back(v);
    }
    int T = 1; //루트노드
               //BFS
    int r = 1;
    visit[T] = 1;
    st[++top] = T;
    q[++rear] = T; //루트 노드
    while (front <= rear)
    {
        int node = q[++front];
        t[node].rank = r++; //탐색하여 탐색우선순위 지정.
        for (std::vector<int>::iterator it = t[node].ad_vertex.begin(); it != t[node].ad_vertex.end(); ++it)
        {
            if (visit[*it] != 1) //방문하지 않았다면
            {
                visit[*it] = 1;
                q[++rear] = *it;
                st[++top] = *it;
            }
        }
    }
    for (int i = top; i > 0; --i)
    {
        int index = st[i];
        t[index].none = 0;
        t[index].early = 1;
        for (int j = 0; j < t[index].ad_vertex.size(); ++j)
        {
            int chlidIdx = t[index].ad_vertex[j];
            t[index].none += t[chlidIdx].early;
            t[index].early += std::min(t[chlidIdx].early, t[chlidIdx].none);
        }
    }
    printf("%d", std::min(t[T].none, t[T].early));
    return 0;
}
