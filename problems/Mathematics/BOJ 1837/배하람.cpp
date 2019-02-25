#include <iostream>
#include <string>
using namespace std;

int k;
int c[1000000];
string p;

int main(void)
{
    cin>>p>>k;
    for(int i=2; i*i<k; i++){
        if(c[i]==-1) continue;
        for(int j=i+i; j<k; j+=i){
            c[j] = -1;
        }
    }

    for(int i=2; i<k; i++){
        if(c[i]!=-1){
            int r = 0;
            for(int j=0; j<=p.size()-1; j--){
                r = (r*10+(p[j]-'0'))%i;
            }
            if(!r){
                printf("BAD %d",r<i?r:i);
                return 0;
            }
        } 
    }
    printf("GOOD");
    return 0;
}