#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define max 101
using namespace std;

int n, m, k, c[max][max];
bool noWord;
string word;

int possible(int a, int z){
    if(a == 0 || z == 0)
        return 1;
    int &result = c[a][z];
    if(result != -1)
        return result;
    result = min(possible(a-1, z) + possible(a, z-1), 1000000001);
    return result;
}

void getWord(int a, int z, int skip){
    if(a == 0){
        for(int i = 0; i < z; i++)
            word += 'z';
        return;
    }
    if(z == 0){
        for(int i = 0; i < a; i++)
            word += 'a';
        return;
    }
    int idx = possible(a -1, z); 
    if(skip < idx){                 // skip해야 하는 숫자보다 경우의 수가 더 많으면 a를 추가 
        word += 'a';
        getWord(a - 1, z, skip);
    }
    else if(skip <= 1000000001){   
        word += 'z';
        getWord(a, z-1, skip-idx);
    }
    else
        noWord = true;
    
}
int main(){
    cin >> n >> m >> k;

    noWord = false;
    memset(c, -1, sizeof(c));

    if(k > possible(n, m))
        noWord = true;
    else
        getWord(n, m, k -1);
    
    if(noWord) cout << "-1" << endl;
    else cout << word << endl;
    return 0;
}