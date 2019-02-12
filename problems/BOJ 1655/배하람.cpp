#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<int,vector<int>,less<int> > pq_max;
priority_queue<int,vector<int>,greater<int> > pq_min;

int n,d,ans;

int main(void)
{
    scanf("%d",&n);
    scanf("%d",&d);
    ans = d;
    printf("%d\n",ans);
    for(int i=1; i<n; i++){
        scanf("%d",&d);
        int size = pq_min.size()+pq_max.size()+2;
        if(size%2==0){
            if(d>ans) pq_min.push(d);
            else if(pq_max.size()){
                pq_min.push(ans);
                if(pq_max.top()>d){
                    ans = pq_max.top();
                    pq_max.pop();
                    pq_max.push(d);
                }else{
                    ans = d;
                }
            }else{
                pq_min.push(ans);
                ans = d;
            }
        }else{
            if(d<ans) pq_max.push(d);
            else if(pq_min.size()){
                pq_max.push(ans);
                if(pq_min.top()<d){
                    ans = pq_min.top();
                    pq_min.pop();
                    pq_min.push(d);
                }else{
                    ans = d;
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}