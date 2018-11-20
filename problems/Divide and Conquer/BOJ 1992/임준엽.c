    //
    //  main.c
    //  HelloWorld
    //
    //  Created by 임준엽 on 19/11/2018.
    //  Copyright © 2018 임준엽. All rights reserved.
    //

    #include <stdio.h>

    int array[100][100];

    void divide_and_conquer(int length, int row, int col){
        
        int standard;
        int flag=0;
        
        standard = array[row][col];
        
        for(int i=row;i<row+length;i++){
            for(int j=col;j<col+length;j++){
                if(standard != array[i][j]){
                    length=length/2;
                    //printf("length is %d\n",length);
                    printf("(");
                    divide_and_conquer(length,row,col);
                    //printf("a");
                    divide_and_conquer(length,row,col+length);
                    //printf("b");
                    divide_and_conquer(length,row+length,col);
                    //printf("c");
                    divide_and_conquer(length,row+length,col+length);
                    //printf("d");
                    printf(")");
                    flag = 1;
                    break;
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
        //printf("flag value is %d\n",flag);
        if(flag != 1)
            printf("%d",standard);
    }

    int main(int argc, const char * argv[]) {

        int i;
        int j;
        int size;

        //printf("type size\n");
        scanf("%d",&size);
        
        for(i=0; i<size; i++){
            for(j=0; j<size; j++){
                //printf("type number 1 or 0\n");
                scanf("%d",&array[i][j]);
            }
        }
    /*
        for(i=0; i<size; i++){
            for(j=0; j<size; j++){
                printf("%d",array[i][j]);
            }
            printf("\n");
        }
     */
        //printf("the answer is\n");
        
        divide_and_conquer(size,0,0);
        
        //printf("\n");
    }


