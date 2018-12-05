
#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

#define FROM 0
#define TO 1
#define WEIGHT 2
vector<tuple<int,int,int>> net;
int parent[1001];


bool compValue(const tuple<int,int,int> &a, const tuple<int,int,int> &b){
    return (get<WEIGHT>(a) < get<WEIGHT>(b));
}

int find(int c){
    if(c == parent[c]) return c;
    return parent[c] = find(parent[c]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    
    parent[b] = a;
}


int main(){
    int V, E, from, to, weight, minSum=0;

    scanf("%d %d", &V, &E);
    
    for(int i = 1; i <= V; i++)
        parent[i] = i;
    
    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &from, &to, &weight);
        net.push_back(make_tuple(from,to,weight));
    }
    
    sort(net.begin(), net.end(), compValue);
    
    int a, b;
    for(int i = 0; i < net.size(); i++){
        a = get<FROM>(net[i]);
        b = get<TO>(net[i]);
        if(find(a) != find(b)){
            merge(a,b);
            minSum += get<WEIGHT>(net[i]);
        }
    }
    cout << minSum;
    return 0;
}
