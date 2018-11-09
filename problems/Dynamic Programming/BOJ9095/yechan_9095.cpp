// baekjoon 9095
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	int num;
	cin >> T;

	int minDP[11] = {0};
	minDP[3] = 4; minDP[2] = 2; minDP[1] = 1;
	for(int i = 4; i < 11; i++)
		minDP[i] = minDP[i-1]+minDP[i-2]+minDP[i-3];
	for(int i = 0; i < T-1; i++){
		cin >> num;
		cout << minDP[num] << endl;
	}
	cin >> num;
	cout << minDP[num];
	return 0;
}
