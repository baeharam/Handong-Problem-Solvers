#include <cstdio>
#include <stdio.h>
#include <iostream>
using namespace std;

int k; //부등호의 총 갯수
int v_min[10];
int v_max[10];
char edge[9];

void find_max(int v, int start, int index){
    if(index == k)
    {
        for(int i = index; i >= start; i--){
            v_max[i] = v;
            v--;
        }
        return;
    }
    if(edge[index] == '>' ){
        for(int i = index; i >= start; i--){
            v_max[i] = v;
            v--;
        }
        start = index + 1;
    }
    find_max(v,start,index+1);
}

void find_min(int v, int start, int index){
    if(index == k)
    {
        for(int i = index; i >= start; i--){
            v_min[i] = v;
            v++;
        }
        return;
    }
    if(edge[index] == '<'){
        for(int i = index; i >= start; i--){
            v_min[i] = v;
            v++;
        }
        start = index + 1;
    }
    find_min(v,start,index+1);
}
int main()
{
    cin >> k;
    while(k < 2 || k > 9)
        cin >> k;
        
    for(int i = 0; i < k; i++)
        cin >> edge[i];

    find_max(9,0,0);
    find_min(0,0,0);
    
    for(int i = 0; i <= k; i++)
        printf("%d",v_max[i]);
    printf("\n");
    for(int i = 0; i <= k; i++)
        printf("%d",v_min[i]);


    return 0;
}

    
  
