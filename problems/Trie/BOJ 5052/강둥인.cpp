#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

struct Trie {
  Trie * node[10];
  bool output, goexist;

  Trie() {
    memset(node, 0, sizeof(node));
    output = goexist = false;
  }
  ~Trie() {
    for (int i = 0; i < 10; i++) {
      if (node[i])
        delete node[i];
    }
  }

  bool insert(const char * key) {
    if (*key == '\0') {
      output = true;
      return goexist;
    }

    int next = * key - '0';
    if (!node[next]) {
      node[next] = new Trie;
    }

    goexist = true;
    return output || node[next]->insert(key+1);
  }
};

int main () {
  int t, n;
  char pNum[11];

  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;

    Trie * root = new Trie;
    bool result = true;

    for (int j = 0; j < n; j++) {
      scanf("%s", pNum);
      if (result && root->insert(pNum))
        result = false;
    }

    puts(result ? "YES" : "NO");
    delete root;
  }
}
