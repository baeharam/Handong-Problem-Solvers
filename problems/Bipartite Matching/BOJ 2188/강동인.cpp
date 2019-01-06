#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX 201
using namespace std;

vector<int> hope[MAX];
int room[MAX];
int crowded[MAX];
int check_room(int w);


int main() {
  int N, M;
  int answer = 0;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int count, want;
    cin >> count;

    while (count--) {
      cin >> want;
      hope[i].push_back(want);
    }
  }

  for (int i = 0; i <= N; ++i) {
    fill(crowded, crowded + N, 0);

    if (check_room(i)) {
      ++answer;

    }
  }

  cout << answer;
}

int check_room(int w) {
  if (crowded[w])
    return 0;

  crowded[w] = 1;
  // 원하는 방에 들어갈 수 잇는가
  for (int c : hope[w]) {
    // 방이 비었거나, 다른 방으로 옮길수 있거나
    if (!room[c] || check_room(room[c])) {
      room[c] = w;
      return 1;
    }
  }
  return 0;

}
