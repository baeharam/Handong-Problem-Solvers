//Baekjoon 2110 Odsn
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {

	int n, c;
	int x[200000];

	scanf("%d %d", &n, &c);	
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	//집들의 거리를 sorting
	sort(x, x + n);

	//left는 최소거리, right는 최대보다 큰 불가능한 거리로 설정.
	int left = 1, right = x[n - 1] + 1;
	int mid, cnt, start;
	int result;


	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 1;
		start = 0;

		for (int i = 0; i < n; i++) {
			// mid 값보다 크거나 같아야 최대거리를 만족.
			if (x[i] - x[start] >= mid) {
				start = i;
				cnt++;
			}				
		}

		// 공유기 갯수만큼 집들의 간격이 최대거리를 만족하면 결과 확정. 
		// 그리고 이게 최대라면 mid의 값이 right의 값임. 최대보다 작으면 right보다 작음.
		// right보다 크게 나오면 while문을 빠져나감.
		if (cnt >= c) {
			result = mid;
			left = mid + 1;
		}
		// 공유기를 다 못달음 = 설정한 최대거리가 너무 멈 = 최대거리는 right보다는 가까움
		else
			right = mid - 1;
	}

	printf("%d", result);

	return 0;
}