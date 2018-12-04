#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>


using namespace std ;




class Node{

    public:

    int name ;
    bool select ;
};

class Edge{

    public:

    int start ;
    int destination ;

    int weight ;

};

void quick_sort(Edge a[] , int b);

int main(){

    
    int ct = 0 ;
    int com ;
    int num ;
    int result = 0 ;

    cin >> com ;
    cin >> num ;

    Edge line[num] ;
    Node computer[com] ;
    
    for(int i = 0 ; i < com ; i++)
    {
        computer[i].select = false ;
    }

    for(int i = 0 ; i < num ; i++)
    {
        cin >> line[i].start >> line[i].destination >> line[i].weight ;
    }
    
    quick_sort(line, num);

    for(int ct = 0 ; ct < com ; ct++)
    {
        if((computer[line[ct].start-1].select==false)||
        (computer[line[ct].destination-1].select==false))
        {
            result += line[ct].weight ;
            computer[line[ct].start-1].select = true ;
            computer[line[ct].destination-1].select = true ;
        }
    }



    cout << result ;

}



void recursive_qsort(Edge a[], int left, int right)
{
        int i = left;
        int j = right;
        int pivot = a[left].weight;

        while(i < j){

                if(i==left) i++;

                for(;a[i].weight < pivot ; i++){
                        if(i > right) break;
                }
                for(;a[j].weight > pivot ; j--){
                        if(j < left) break;
                }

                if(i < j)   swap(a[i], a[j]);
                else
                {
                        swap(a[left], a[j]);
                        recursive_qsort(a, left, j-1);
                        recursive_qsort(a, j+1, right);
                }

        }
        return ;

}

void quick_sort(Edge line[], int num)
{
    recursive_qsort(line, 0, num-1);
}

void swap(Edge &one, Edge &two)
{
    Edge tmp = one ;
    one = two ; 
    two = tmp ;
}