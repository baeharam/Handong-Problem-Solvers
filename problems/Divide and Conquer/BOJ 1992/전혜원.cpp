#include <iostream>
#include <cstdio>

using namespace std ;

bool isSame(int start_x, int start_y, int num) ;
string quadTree(int start_x, int start_y, int num) ;

char **input ;

int main(int argc, char** argv) {
    int num = 0 ;
    scanf("%d", &num) ;
    
    input = new char*[num] ;

    for (int i=0 ; i < num ; i++) {
        input[i] = new char[num + 1] ;
        scanf("%s", input[i]) ;
    }

    string result ;
    result = quadTree(0, 0, num) ;

    cout << result << endl ;

    for (int i=0 ; i<num ; i++) {
        delete []*(input+i) ;
    }
    delete [] input ;
}

bool isSame(int start_x, int start_y, int num) {
    char crtr = input[start_x][start_y] ;
    for (int i=start_x ; i<start_x+num ; i++) {
        for (int j=start_y ; j <start_y+num ; j++) {
            if(input[i][j]!=crtr)
                return false ;
        }
    }
    return true ;
}

string quadTree(int start_x, int start_y, int num) {
    string output ;
    output = "" ;

    if (num == 1) {
        output += input[start_x][start_y] ;
        return output ;
    }

    if (isSame(start_x, start_y, num)) {
        output += input[start_x][start_y] ;
    } else {
        output += "(" ;
        output += quadTree(start_x,       start_y,       num/2) ;
        output += quadTree(start_x,       start_y+num/2, num/2) ;
        output += quadTree(start_x+num/2, start_y,       num/2) ;
        output += quadTree(start_x+num/2, start_y+num/2, num/2) ;
        output += ")" ;
    }
    return output ;
}