#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int> > h1;
priority_queue<int,vector<int>,greater<int> > h2;
void swap(int a, int b){
    h1.pop(); h2.pop();
    h1.push(b); h2.push(a);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, tmp;
    cin>>n; n--;
    cin>>tmp; h1.push(tmp);
    cout<<tmp<<"\n";
    while(n--){
        cin>>tmp;
        if(h1.size() > h2.size()) h2.push(tmp);
        else h1.push(tmp);
        if(h1.top() > h2.top()) swap(h1.top(),h2.top());
        if(h1.size() < h2.size()) cout<<h2.top()<<"\n";
        else cout<<h1.top()<<"\n"; 
    }
}