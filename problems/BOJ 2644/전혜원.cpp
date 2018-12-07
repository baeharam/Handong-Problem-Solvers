#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv) {
    int people_num, test_case, people_1, people_2 ;
    int connect[101][101] = {0, } ;
    int dist[101] = {0,};

    cin >> people_num ;
    scanf("%d %d", &people_1, &people_2) ;
    cin >> test_case ;

    int chon_list[test_case] ;
    for (int i=0 ; i<test_case ; i++) {
        int x, y ;
        scanf("%d %d", &x, &y) ;
        connect[x][y] = 1 ;
        connect[y][x] = 1 ;
    }
    //printf("\n\n%d %d\n\n", people_1, people_2) ;

    queue <int> q ;
    q.push(people_1) ;

    while(!q.empty()) {
        int curr = q.front() ;
        q.pop() ; // pop out

        for (int i = 1; i <= people_num; i++) {
            if (connect[curr][i] == 0 || dist[i] != 0) 
                continue;
            dist[i] = dist[curr] + 1;
            q.push(i);
        }
    }

    if (dist[people_2] == 0)
        printf("-1\n") ;
    else
        cout << dist[people_2] << endl ;

   
}