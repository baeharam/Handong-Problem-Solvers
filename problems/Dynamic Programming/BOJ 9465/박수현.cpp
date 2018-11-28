#include <cstdio>
#include <iostream>
using namespace std;


int sticker[2][100000] ;
int score[2][100000] ;


int find(int num, int x, int y)
{
	if(score[y][x]!=-1) return score[y][x] ;

	if(num == 1)
	{
		score[y][x] = sticker[y][x] ;
		return score[y][x] ;
	}
	if(num == 2)
	{
		if(y == 0)
		{
			score[y][x] = sticker[y][x] + find(num-1, x+1, 1) ;
			return score[y][x] ;
		}
		else if(y == 1)
		{
			score[y][x] = sticker[y][x] + find(num-1, x+1, 0) ;
			return score[y][x] ;
		}
	}	

	if(y == 0)
	{
		int case1 = find(num-1, x+1, 1);
		int case2 = find(num-2, x+2, 1);

		if(case1 < case2)
		{
			score[y][x] = sticker[y][x] + case2 ;
			return score[y][x] ;
		}
		else
		{	
			score[y][x] = sticker[y][x] + case1 ;
			return score[y][x] ;
		}
	}	
	else
	{
		int case1 = find(num-1, x+1, 0) ;
		int case2 = find(num-2, x+2, 0) ;

		if(case1 < case2)
		{
			score[y][x] = sticker[y][x] + case2 ;
			return score[y][x] ;
		}
		else 
		{	
			score[y][x] = sticker[y][x] + case1 ; 
			return score[y][x] ;
		}
	}
};

int main(){

	int t_case ;
	cin >> t_case ;
	int answer[t_case];
	
	for(int i = 0; i < t_case ; i++)
	{
		int num ;
		cin >> num ;


		for(int m = 0; m < 2 ; m++)		
		for(int j = 0; j < num ; j++)
		{
			score[m][j] = -1 ;
			cin >> sticker[m][j] ;
		}
		int case1 = find(num, 0, 0) ;
		int case2 = find(num, 0, 1) ;
		
		if(case1 < case2) answer[i] = case2;
		else answer[i] = case1 ;
	}
			
	for(int i =0; i < t_case ; i++)
	{	
		cout << answer[i] ;
		cout << "\n" ;
	}
}
