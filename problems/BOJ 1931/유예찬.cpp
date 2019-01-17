//baekjoon 1931
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	int tmp1, tmp2;
	int last;
	int count = 0;
	cin >> N;
	vector<pair<int,int>> pv;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp1 >> tmp2;
		pv.push_back(make_pair(tmp2,tmp1));
	}
	sort(pv.begin(), pv.end());
	last = pv[0].first;
	count = 1;
	for (int i = 1; i < N; ++i)
	{
		if(last <= pv[i].second){
			count++;
			last = pv[i].first;
		}
	}
	cout << count;
}