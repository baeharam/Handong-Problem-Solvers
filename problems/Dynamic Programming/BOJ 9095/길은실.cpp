/*
** program name : BOJ_9095
** student name : Gil Eunsil
** student id : 21600035
** date : 2018.11. 14
** e-mail : 21600035@handong.edu
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define ARRAY_SIZE 11

int main(){
	
	int T, n, arr[ARRAY_SIZE];
	
	cout << "\nEnter the 'T' value : ";
	cin >> T;
	
	/*Base Case*/
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	/*General Case*/
	for(int i = 4; i < ARRAY_SIZE; i++)
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	
	while(T--){
		cout << "\nEnter the 'n' value : ";
		cin >> n;
		cout << "The result is " << arr[n];
	}
}
