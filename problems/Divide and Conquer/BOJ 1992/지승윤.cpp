#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int n;
int a[64][64];
void q(int size, int x, int y) {
    if (size == 1) {
        cout<<a[y][x];
        return;
    }
    bool eq = true;
    for (int i = y; i < y + size; i++) {
        if (!eq) 
            break;
        for (int j = x; j < x + size; j++) {
            if (a[y][x] != a[i][j]) {
                eq = false;
                break;
            }
        }
    }
    if (eq) {
        cout<<a[y][x];
        return;
    }
    int ns = size / 2;
    cout<<"(";
    q(ns, x, y);
    q(ns, x + ns, y);
    q(ns, x, y + ns);
    q(ns, x + ns, y + ns);
    cout<<")";
}
int main(void) {
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    q(n, 0, 0);
    cout<<endl;
    return 0;
}