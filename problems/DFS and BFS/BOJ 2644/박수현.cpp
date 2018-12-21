//촌수계산
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std ;

class Pair{
    public:
    int parent ;
    int child ; 
};

Pair connect[101] ;
queue<int> myQ, vQ, tmp;

int relation ;

int find(int , int );

bool check(int checker) ;

int main(){

    int P ;
    int target1, target2 ;

    cin >> P >> target1 >> target2 >> relation ;

    for(int i = 0 ; i < relation ; i++)
        cin >> connect[i].parent >> connect[i].child ;
    
    cout << find(target1, target2) ;
}

int find(int target1, int target2)
{
    int ct = 1 ;

    myQ.push(target1) ;
    vQ.push(target1)  ;

    while(myQ.empty()==false)
    {
       int compare = myQ.front() ;
       myQ.pop() ;

        for(int i = 0 ; i < relation ; i++)
        {
            if(connect[i].parent == compare){
                if(connect[i].child == target2){
                    return ct ;
                }
                else{
                    if(check(connect[i].child)==true){
                        tmp.push(connect[i].child) ;
                        vQ.push(connect[i].child) ;
                    }
                }
            }
            else if(connect[i].child == compare){
                if(connect[i].parent == target2){
                    return ct ;
                }
                else{
                    if(check(connect[i].parent)==true){
                        tmp.push(connect[i].parent) ;
                        vQ.push(connect[i].parent) ;
                    }
                }
            }
        }

        if(myQ.empty()==true)
        {

            ct++ ;
            while(tmp.empty()==false)
            {
                myQ.push(tmp.front());
                tmp.pop() ;
            }
            
        }
    }
    return -1 ;
}

bool check(int checker){

    queue<int> tmpQ ;
    tmpQ = vQ ;
    for(int i = 0 ; i < vQ.size() ; i++)
    {
        if(checker == tmpQ.front()) return false ;
        tmpQ.pop() ;
    }
    return true ;
}