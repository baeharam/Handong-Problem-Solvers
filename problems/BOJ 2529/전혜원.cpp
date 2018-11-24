#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

char digit[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
vector<string> v;
char *sign ;
int input_K ;

void swap(int i, int j)
{
    char temp = digit[i] ;
    digit[i] = digit[j] ;
    digit[j] = temp ;
}

void permutation(int len, int n, int k) {
    if (len == k) { 
        string j = "" ;
        bool flag = true ;
        for (int i=0 ; i<len ; i++) {
            j += digit[i] ;
        }
        for (int i=0 ; i<input_K ; i++) {
            int answer_A = j[i] - '0' ;
            int answer_B = j[i+1] - '0' ;

            if (sign[2*i+1] == '<') {
                if(answer_A > answer_B) {
                    flag = false ;
                    break;
                }
            } else { 
                if(answer_A < answer_B) {
                    flag = false ;
                    break;
                }
            }
        }
        if (flag == true)
            v.push_back(j) ;
    } else {
        for (int i = len ; i < n ; i++)
        {
            swap(len, i);
            permutation(len+1, n, k);
            swap(len, i); //backtrack
        }
    }
}
 

int main(int argc, char** argv) {
    scanf("%d", &input_K) ;
    sign = new char[2*input_K+1] ;

    for (int i=0 ; i<2*input_K+1 ; i++) {
        scanf("%c", &sign[i]) ;
    }
/*
    for (int i=0 ; i<input_K ; i++) {
        printf("%c\n", sign[2*i+1]) ;
    }
*/
    permutation(0, 10, input_K+1);

    vector<string>::iterator iter = v.begin(); 
    string max_num, min_num ;
    bool first = true ;

    for (iter = v.begin(); iter != v.end(); iter++) {
        if (first==true) {
            max_num = *iter ;
            min_num = *iter ;
            first = false ;
            continue ;
        }
        if (max_num.compare(*iter) < 0) 
            max_num = *iter ;
        if (min_num.compare(*iter) > 0)
            min_num = *iter ;
    }
        //cout << *iter << endl ;
    cout << max_num << endl ;
    cout << min_num << endl ;

    delete sign ;
    return 0;
}
