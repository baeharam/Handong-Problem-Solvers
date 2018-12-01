#include <iostream>
#include <cstdio>

#define MAX_SIZE 200000
using namespace std;
 
int main(int argc, char** argv) {
    int home, share ;
    scanf("%d %d", &home, &share) ;
 
    int distance[MAX_SIZE] = {0, } ;

    for (int i = 0; i < home; i++) {
        cin >> distance[i] ;
    }

    sort(distance, distance + home) ;
 
    int left = 1 ;
    int right = distance[home - 1] ;
    int max_len = 0 ;
 
    while (left <= right) {
        int mid = (left + right) / 2 ;   
        int cnt = 1 ;  
        int start = distance[0] ;
 
        for (int i = 1 ; i<home ; i++) {
            if (distance[i] - start >= mid) {
                start = distance[i] ;
                cnt = cnt + 1 ;
            }
        }

        if (cnt >= share) {
            max_len = mid;
            left = mid + 1;
        } else 
            right = mid - 1;
    }

    cout << max_len << endl;
}