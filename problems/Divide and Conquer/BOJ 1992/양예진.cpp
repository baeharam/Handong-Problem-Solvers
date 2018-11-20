//
//  main.cpp
//  quadTree
//
//  Created by 양예진 on 2018. 11. 20..
//  Copyright © 2018년 양예진. All rights reserved.
//

#include <iostream>
using namespace std;
char qtree[64][64];
string result = "";



bool check(int r, int c, int size){
    
    int color = qtree[r][c];
    
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            if(color != qtree[r+i][c+j])
                return false;
    
    return true;
}

void compression(int r, int c, int size){
    bool same = check(r,c,size);
    
    if(same)
        result += qtree[r][c];
    
    else{
        result += "(";
        size /= 2;
        
        compression(r, c, size);           // top_left
        
        compression(r, c+size, size);      // top_right
        
        compression(r+size, c, size);      // bottom_left
        
        compression(r+size, c+size, size); // bottom_right
        result += ")";
    }
    
}


int main(){
    int N;
    cin >> N;
    
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> qtree[i][j];
    compression(0,0,N);
    cout << result << "\n";
    return 0;
}
