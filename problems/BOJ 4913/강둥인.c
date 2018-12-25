#include <stdio.h>
#include <string.h>

int primeNum[1000000];
int count = 0;
int count_Ferma = 0;

void prime(int start, int end);

int main() {
    
    int a[1000];
    int b[1000];
    int i = 0;
    
    
    for ( ; ; i++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] == -1 && b[i] == -1)
            break;
    }
    
    for (int j = 0; j < i; j++) {
        printf("%d %d ", a[j], b[j]);
        prime(a[j], b[j]);
    }
    
}

void prime(int start, int end) {
    int i,j;
    
    for (i = start; i <= end; i++) {
        if (start == -1 && end == -1)
            return;
        
        for (j = 2; j < i; j++) {
            if ((i % j) == 0) {
                break;
            }
            
            if (i == j) {
                primeNum[count] = i;
                count++;
            }
        }
    }
    
    for (int i = 0; i < count; i++) {
        if (primeNum[i] % 4 == 1) {
            count_Ferma++;
        }
    }
    
    printf("%d %d\n", count, count_Ferma);
    count = 0;
    count_Ferma = 0;
    
}


