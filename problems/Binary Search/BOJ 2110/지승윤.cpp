#include<iostream>
#include<algorithm>
#define MAX 1000000000
using namespace std;
int n,k;
int a[999999];

int f(int x)
{
    int cnt=1,i,s=a[0];
    for(i=0;i<n;i++){
        if(a[i]-s>=x)s=a[i],cnt++;
    }
    return cnt>=k;
}

int main()
{
    int i,m,s=1,e=MAX,mem;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    while(s<=e){
        m=(s+e)/2;
        if(f(m)){
            mem=m;
            s=m+1;
        }
        else e=m-1;
    }
    cout<<mem;
    return 0;
}
