#include<cstdio>
#include<iostream>

using namespace std;

int COM, MAX = 9999;
int arr[1001][1001];
int dist[1001];

int prim() {
    int mini, index, sum = 0;
    
    for (int i = 1; i <= COM; i++)
        dist[i] = arr[1][i];
    dist[1] = -1;
    
    for (int j = 1; j < COM; j++) {
        mini = MAX;
        for (int i = 1; i <= COM; i++) {
            if (dist[i] != -1 && dist[i] < mini) {
                mini = dist[i];
                index = i;
            }
        }
        sum += mini;
        dist[index] = -1;
        
        for (int i = 1; i <= COM; i++) {
            if (dist[i] > arr[index][i])
                dist[i] = arr[index][i];
        }
    }
    return sum;
}

int main() {
    int line, com1, com2, weigh;
    scanf("%d %d", &COM, &line);
    
    for (int i = 1; i <= COM; i++) {
        for (int j = 1; j <= COM; j++) {
            arr[i][j] = MAX;
            if (i == j)
                arr[i][j] = 0;
        }
    }
    
    for (int i = 0; i < line; i++) {
        scanf("%d %d %d", &com1, &com2, &weigh);
        arr[com1][com2] = arr[com2][com1] = weigh;
    }
    
    printf("%d\n", prim());
    
    return 0;
}
