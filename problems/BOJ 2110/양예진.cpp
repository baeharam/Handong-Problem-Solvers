#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int pos[200000];

bool check(int dist){
    int count = 1;
    int prev = pos[0];
    for(int i = 1; i < N; i++){
        if(pos[i]-prev >= dist){
            count++;
            prev = pos[i];}
    }
    
    if(count >= C)
        return true;
    return false;
}

int main(int argc, const char * argv[]) {
    int right, left, middle;
    
    scanf("%d %d", &N, &C);
    
    for(int i = 0; i < N; i++){
        cin >> pos[i];
    }
    sort(pos,pos+N);
    
    right = pos[N-1] - pos[0]; // 최대 거리
    left = 1;                  // 최소 거리
    int result = 0;
    while(left <= right){
        middle = (left + right) / 2;
        
        if(check(middle)){
            result = result > middle ? result : middle;
            left = middle + 1;
        }
        else
            right = middle-1;

    }
    
    cout << result << "\n";

    return 0;
}
