#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
	
int main(){
	
	int house_N ;
	int share_N ;
	
	int high = 0, low;
	cin >> house_N >> share_N ;	
	
	int house_X[house_N] ;
	
	for(int i = 0; i < house_N; i++)
	{
		cin >> house_X[i] ;
	}
	
	sort(house_X, house_X + house_N - 1) ;

	int left = 1 ;
	int right = house_X[house_N - 1] - house_X[0] ;

	int distance ;
	int sol ;
	
	while(left <= right){

		int count = 1 ; //공유기 설치 갯수 확인(처음 집에는 무조건 설치해서 1로 시작)

		int mid = (left + right) / 2 ; 	//중간값 찾기
		int start = house_X[0] ;		//공유기 설치를 시작하는 위치 
		
		
		for(int i = 0; i < house_N; i++)
		{
			distance = house_X[i] - start ;

			if(mid <= distance)
			{
				count++ ;
				start = house_X[i] ;
			}
		}
		
		if(count < share_N)
		{
			right = mid - 1 ;
		}
		else
		{
			sol = mid ;
			left = mid + 1 ;
		}

	}

	cout << sol ;
}