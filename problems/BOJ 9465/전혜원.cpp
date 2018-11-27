#include <iostream>
#include <cstdio>

using namespace std ;

int big(int a, int b) {
    return (a>b) ? a : b ;
}

int **grid ;
int **price ;

int main(int argc, char** argv) {
    int test = 0;
    scanf("%d ", &test) ;
    int* answer = new int[test] ;
    for (int iter=0 ; iter<test ; iter++) {
        int input_ = 0 ;
        scanf("%d ", &input_) ;
        int input = (input_>2)? input_ : 2 ;

        grid = new int*[2] ;
        price = new int*[2] ;

        for (int i=0 ; i<2 ; i++) {
            grid[i] = new int[input] ;
            price[i] = new int[input] ;
        }

        for (int i=0 ; i<2 ; i++) {
            for (int j=0 ; j<input ; j++) {
                cin >> grid[i][j] ;
            }
        }
        // size -> price[2][input]

        // base case
        price[0][0] = grid[0][0] ;
        price[1][0] = grid[1][0] ;
        price[0][1] = grid[1][0] + grid[0][1] ; 
        price[1][1] = grid[0][0] + grid[1][1] ;

        // general case
        for (int i=2 ; i<input ; i++) {
            price[0][i] = big(price[1][i-1], price[1][i-2]) + grid[0][i] ;
            price[1][i] = big(price[0][i-1], price[0][i-2]) + grid[1][i] ;
        }
        answer[iter] =  big(price[0][input_-1], price[1][input_-1]) ;

        for (int i=0 ; i<2 ; i++) {
            delete grid[i] ;
            delete price[i] ;
        }

        delete grid ;
        delete price ;
    } 

    for (int i=0 ; i<test ; i++) {
        cout << answer[i] << endl ;
    }
}

