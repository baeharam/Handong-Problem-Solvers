#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int k;
char ine[10];

bool check(vector<int> &num) {
	for (int i = 0; i < k; i++) {
		if (ine[i] == '<' && num[i] > num[i + 1])
			return false;
		if (ine[i] == '>' && num[i] < num[i + 1])
			return false;
	}
	return true;
}

int main(void)
{
	vector<int> max_num, min_num;

	scanf("%d", &k);

	for (int i = 0; i < k; i++) scanf("%s", &ine[i]);

	for (int i = 0; i <= k; i++) {
		max_num.push_back(9 - i);
		min_num.push_back(i);
	}

	while(1)
	{
		if (check(max_num))
			break;

		prev_permutation(max_num.begin(), max_num.end());
	}

	while(1)
	{
		if (check(min_num))
			break;

		next_permutation(min_num.begin(), min_num.end());
	}

	for (int i = 0; i <= k; i++)
		printf("%d", max_num[i]);

	printf("\n");

	for (int i = 0; i <= k; i++)
		printf("%d", min_num[i]);

	return 0;
}
