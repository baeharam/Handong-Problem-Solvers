#include <cstdio>
#include <cmath>
#include <vector>

const int U_MAX = 1000000;
int l,u,x,y;
int eratos[U_MAX+1];
std::vector<int> prime;


int main(void)
{
    for(int i=2; i<=U_MAX; i++) eratos[i] = i;
    for(int i=2; i<=(int)std::sqrt(U_MAX); i++){
        for(int j=i*2; j<=U_MAX; j+=i){
            if(eratos[j]==-1) continue;
            else if(eratos[j]%i==0) eratos[j]=-1;
        }
    }
    for(int i=2; i<=U_MAX; i++){
        if(eratos[i]!=-1)
            prime.push_back(eratos[i]);
    }

    while(true){
        scanf("%d%d",&l,&u);
        if(l==-1 && u==-1) break;
        x = 0, y = 0;
        int k = 0;
        while(k<prime.size() && prime[k]<=u){
            if(prime[k]<l){
                k++;
                continue;
            }
            x++;
            if(prime[k]%4==1)
                y++;
            k++;
        }
        if(l<=2 && u>=2) y++;
        printf("%d %d %d %d\n",l,u,x,y);
    }
    return 0;
}