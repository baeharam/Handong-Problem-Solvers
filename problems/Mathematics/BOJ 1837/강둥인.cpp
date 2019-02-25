#include <cstdio>
#include <algorithm>

using namespace std;

char p[110];
int password[2000000];
int K;

bool checks(const char *s, int p) {
  int ret = 0;
  for (int i = 0; s[i]; i++) {
    ret = (ret * 10 + s[i] - '0') % p;
  }

  return !ret ? true : false;

}

int main() {
  //너무 큰 수라 string으로 받고 나중에 변환
  scanf("%s%d", &p, &K);

  //에라토스테네스의 체
  for (int i = 2; i < 2000000; i++) {
    if(p[i]) continue;
    for (int j = i + i; j < 2000000; j += i)
      p[j] = true;
  }

  int r = 0, less_prime = 100000000;
  for (int i = 2; i <= K; i++) {
    if(p[i]) continue;
    if (checks(p, i)) {
      r = 1;
      less_prime = min(less_prime, i);
    }
  }

  printf("%s ", r ? "BAD" : "GOOD");
  if(r)
    printf("%d\n", less_prime);

  return 0;

}
