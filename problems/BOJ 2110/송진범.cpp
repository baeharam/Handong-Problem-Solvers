#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning(disable : 4996)

typedef long long int ll;
ll arr[200000];
ll n, c;

int main() {

	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

	sort(arr, arr + n);
	ll left = 0;
	ll right = arr[n - 1] - arr[0];
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll crr = 1;
		ll wifi = arr[0];

		for (int i = 1; i < n; i++){
			if (arr[i] - wifi >= mid) {
				crr++;
				wifi = arr[i];
			}
		}
			if (crr < c) {
				right = mid - 1;
			}
			else {
				if (mid > ans)
					ans= mid;
				left = mid + 1;
			}
		}


	printf("%lld\n", ans);

	system("pause");
}
