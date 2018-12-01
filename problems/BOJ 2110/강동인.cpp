//
//  main.cpp
//  2110
//
//  Created by 강동인 on 01/12/2018.
//  Copyright © 2018 강동인. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int C, N;
vector<int> house;


int main(int argc, const char * argv[]) {
   
    cin >> N >> C;
    
    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d" , &temp);
        house.push_back(temp);
    }
    
    sort(house.begin(), house.end());
    
    int min = 1;
    int max = house.back() - house.front();
   
    
    int answer = -1;
    
    while (min <= max) {
        int mid = (min + max) / 2;
        int prev = 0;
        int wifi_count = 1;
        
        for (int i = 1; i < N; i++) {
            
            if (house.at(i) - house.at(prev) >= mid) {
                prev = i;
                wifi_count++;
            }
        }
        
        if (wifi_count >= C) {
            min = mid + 1;
        }
        else {
            max = mid -1;
        }
        
        if (answer < mid && wifi_count >= C) {
            answer = mid;
        }
    }
    
    cout << answer;
    return 0;
    
    
    
}
