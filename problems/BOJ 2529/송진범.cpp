#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> maxNum, minNum;

string sign;

bool check(vector<int> &number)
{
	for (int i = 0; i < sign.length(); i++)
	{
		if (sign[i] == '<' && number[i] > number[i + 1])
			return false;
		else if (sign[i] == '>' && number[i] < number[i + 1])
			return false;
		return true;
	}
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char temp;
		cin >> temp;
		sign += temp;
	}

	for (int i = 9; i >= 9 - N; i--)
		maxNum.push_back(i);
	while (1) {
		if (check(maxNum))
			break;
		prev_permutation(maxNum.begin(), maxNum.end());
	}
	for (int i = 0; i <= N; i++)
		minNum.push_back(i);
	while (1) {
		if (check(minNum))
			break;
		next_permutation(minNum.begin(), minNum.end());
	}

	for (int i = 0; i < maxNum.size(); i++)
		cout << maxNum[i];
	cout << "\n";

	for (int i = 0; i < minNum.size(); i++)
		cout << minNum[i];
	cout << "\n";

	system("pause");
	return 0;
}