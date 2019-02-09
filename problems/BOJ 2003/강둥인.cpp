#include <cstdio>

using namespace std;

#define MAX 10001

int N, M;
int arr[MAX];
int ans;

void solution() {

    int left = 0, right = 0, now_Sum = arr[0];

    while (left <= right && right < N) {
        // 현재 구간의 합이 m과 같을 경우
        if (now_Sum == M) {
            ans += 1;
            right += 1;
            now_Sum += arr[right];
        }

        // 현재 구간의 합이 m보다 클 경우
        else if (now_Sum > M) {
            now_Sum -= arr[left];
            left += 1;

            // left가 right보다 커진 경우 바꿔준다
            if (left > right && left < N) {
                right = left;
                now_Sum = arr[left];
            }
        }

        // 현재 구간의 합이 m보다 작을 경우
        else if (now_Sum < M) {
            right += 1;
            now_Sum += arr[right];
        }
    }
}

int main() {

  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++)
    scanf("%d", &arr[i]);

  solution();
  printf("%d\n", ans);
  return 0;

}
