#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string inequality;

bool Is_ordered(vector<int>&num) {
        // 부등호가 성립하지 않는 두가지 경우
    for (int i = 0; i < inequality.length(); i++) {
        if (inequality[i] == '<' && num[i] > num[i + 1]) {
            return false;
        }

        else if (inequality[i] == '>' && num[i] < num[i + 1]) {
            return false;
        }
    }

    return true;

}


int main(void) {

    int n;
    vector<int> Max, Min;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        inequality += tmp;
        }

    
    for (int i = 9; i > 9 - (n + 1); i--) {
        Max.push_back(i);
    }

        while (1) {
            if (Is_ordered(Max))
                break;

        prev_permutation(Max.begin(), Max.end());
        }

    
    for (int i = 0; i < (n + 1); i++) {
        Min.push_back(i);
    }

        while (1) {
            if (Is_ordered(Min))
                break;

        next_permutation(Min.begin(), Min.end());
        }

    for (int i = 0; i < Max.size(); i++) {
        cout << Max[i];
    }
        
        cout << "\n";

    for (int i = 0; i < Min.size(); i++) {
        cout << Min[i];
    }

        cout << "\n";

    return 0;

}