#include <cstdio>
#include <iostream>
#include <queue>

using namespace std ;

int prime[1000000];
int prime_index = 0 ;
int check_num = 3 ;

int main(){

    int start[100] ;
    int end[100] ;
    int x[100] ;
    int y[100] ;

    int num = -1;
    int start_num , end_num;
    int x_num, y_num;

    prime[0] = 2 ;
    prime_index = 1;
    
    while(true){
        
        num++;
        cin >> start_num >> end_num ;
        
        if((start_num==-1)&&(end_num==-1)) break ;


        for(int i = 0 ; check_num <= end_num ; check_num++)
        {
            bool check = true;

            for(int j = 0; j < prime_index ; j++)
            {
                if((check_num%prime[j])==0){
                    check = false ;
                    break ;
                }
            }
            if(check == true){
                prime[prime_index] = check_num ;
                prime_index ++ ;
            }  

        }

        x_num = 0 ;
        y_num = 0 ;

        for(int i = 0; i < prime_index; i++)
        {
            if(prime[i]<start_num) continue ;
            else if((start_num <= prime[i])&&(prime[i] <= end_num)){
                x_num++ ;
                if(prime[i]%4==1) y_num++ ;
            }
            else break ;
        }
        start[num] = start_num ;
        end[num] = end_num ;
        x[num] = x_num ;
        y[num] = y_num ;
    }

    for(int i = 0 ; i < num; i++)
    {

        cout << start[i] << " " << end[i] << " " << x[i] << " " << y[i] << "\n" ;
    }
}
