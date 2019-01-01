#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX 5005
#define INF 987654321
#define MOD 31991
using namespace std;
int n;
char a[1000001], b[2000001];
int kmp[1000000];
int ans;
void make_pi()
{
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && a[i] != a[j]) {
      j = kmp[j - 1];
    }
    if (a[i] == a[j])
      kmp[i] = ++j;
  }
}
int get_gcd(int a, int b)
{
  if (b == 0)
    return a;
  return get_gcd(b, a%b);
}
int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf(" %c", &a[i]);
  for (int i = 0; i < n; i++)
    scanf(" %c", &b[i]);
  for (int i = 0; i < n; i++)
    b[n + i] = b[i];
  make_pi();
  int j = 0;
  for (int i = 0; i < n * 2; i++) {
    while (j > 0 && a[j] != b[i]) {
      j = kmp[j - 1];
    }
    if (a[j] == b[i]) {
      if (j == n - 1) {
        if (i - n + 1 < n)
          ans++;
        j = kmp[j];
      }
      else
        j++;
    }
  }
  int gcd = get_gcd(ans, n);
  printf("%d/%d", ans / gcd, n / gcd);
  return 0;
}
