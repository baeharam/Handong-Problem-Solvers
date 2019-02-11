#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int> > minHeap;
priority_queue <int, vector<int>, less<int> > maxHeap;


int main(){
    int n;
    int val;

    scanf("%d", &n);
    while(n--){
        scanf("%d", &val);

        if(maxHeap.size() <= minHeap.size())
            maxHeap.push(val);
        else 
            minHeap.push(val);
        
        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()){
            int a = maxHeap.top();
            int b = minHeap.top();
            maxHeap.pop(); minHeap.pop();
            maxHeap.push(b); minHeap.push(a);
        }
        printf("%d\n", maxHeap.top());
    }
    return 0;
}