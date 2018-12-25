#include <cstdio>
#include <cstring>
using namespace std;
const int Max = 1000001;
int L, U, x, y, T[Max], P[Max];
bool prime[Max];

void Perma()
{
    int pri = 0, total = 0;
    for(int i = 2; i * i < Max; i++){
        if(prime[i])
            for(int j = i + i; j < Max; j += i)
                prime[j] = false;
    }
    for(int i = 1; i < Max; i++){
        if (prime[i]){
            pri++;
            if(i % 4 == 1)
                total++;}
        P[i] = pri;
        T[i] = total;
    }
}

int main(){
    scanf("%d %d", &L, &U);
        while(L != -1 && U != -1){
            memset(prime, true, sizeof(prime));
            Perma();

            if(U < 2)
                x = 0, y = 0;
            if(L < 2)
                x = P[U], y = T[U];
            else {
                x = P[U] - P[L-1];
			    y = T[U] - T[L-1];}
            if(U <= 2 && L >= 2)
                y += 1;

            printf("%d %d %d %d\n", L, U, x, y);
            scanf("%d %d", &L, &U);
        }
    return 0;
}