#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ** board, ** next_board;
int row, column;
int years = 0;
int piece = 1;

void melt();
bool IsTwo();
bool IsAllmelt();

int main() {

    scanf("%d %d", &column, &row);
    
    board = (int **)malloc(sizeof(int *) * column);
    next_board = (int **)malloc(sizeof(int *) * column);

    for (int k = 0; k < row; k++) {
        board[k] = (int *)malloc(sizeof(int) * row);
        next_board[k] = (int *)malloc(sizeof(int) * row);
    }

    for (int i  = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    while (!IsTwo()) {
        melt();
        years++;
        if (IsAllmelt() && piece == 1) {
            printf("0");
            return 0;
        }

    }

    

    printf("%d \n", years);
}

void melt() {
    int count = 0;
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            if (board[i][j] == 0)
                next_board[i][j] = 0;
            
            else {
                if (board[i-1][j] == 0)
                    count++;
                
                if (board[i+1][j] == 0)
                    count ++;
                
                if (board[i][j-1] == 0)
                    count++;
               
                if (board[i][j+1] == 0)
                    count++;
                
                next_board[i][j] = board[i][j] - count;
                if (next_board[i][j] < 0)
                    next_board[i][j] = 0;

                count = 0; 
            }
        }
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

bool IsTwo() {
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            if (board[i][j] == 0) {
                continue;
            }
                
            else {  
                if (board[i+1][j] == 0 && board[i-1][j] == 0 && board[i][j+1] == 0 && board[i][j-1] == 0) {
                    piece++;
                    return true;
                }
            }
        }
    }
    return false;
}

bool IsAllmelt() {
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            if(board[i][j] == 0)
                continue;
            else
                return false;
        }
    }
    return true;
}


