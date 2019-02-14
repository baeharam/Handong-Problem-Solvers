#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

pii A[500005];
pii T[500005];
int ans[500005];

void merge(int s, int m, int e) {

  int p1 = s; int p2 = m; int k = s;
  while (p1 < m && p2 < e) {
    if (A[p1].first <= A[p2].first) {
      T[k++] = A[p1++];
    }

    else {
      int advance = p1 - s;
      int origin_rank = A[p2].second;
      if (advance) {
        ans[origin_rank] -= advance;
    }
      T[k++] = A[p2++];
    }
  }

    while (p1 < m) {
      T[k++] = A[p1++];
    }

    while (p2 < e) {
      int advance = p1 - s;
      int origin_rank = A[p2].second;
      if (advance) {
        ans[origin_rank] -= advance;
      }

        T[k++] = A[p2++];
      }

      for (int i=s; i < e; i++) {
        A[i] = T[i];
      }
    }

    void merge_sort(int s, int e) {
      int m = (s + e) / 2;
      if (s < m) {
        merge_sort(s, m);
        merge_sort(m, e);
        merge(s, m, e);
      }
    }


int main() {
  int n;
  scanf("%d", &n);
  for (int i=1; i <= n; i++) {
    scanf("%d", &A[i].first);
    A[i].second = i; ans[i] = i;
  }

  merge_sort(1, n+1);
  for (int i=1; i <= n; i++) {
    printf("%d\n", ans[i]);
  }

  return 0;
}
