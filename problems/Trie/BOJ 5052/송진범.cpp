#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int t, n;
char number[11];

struct Trie{
  Trie * go[10];

  bool A, B;

  Trie(){
    memset(go, 0, sizeof(go));
    A = B = false;
  }
  ~Trie(){
    for(int i= 0; i< 10; i++){
      if(go[i])
        delete go[i];
    }
  }
  bool insert(const char*key){
    if(*key == '\0'){
      A = true;
      return B;
    }
    int next = *key - '0';
    if(!go[next]){
      go[next] = new Trie;
    }
    B =true;
    return A || go[next]->insert(key+1);
  }
};

int main(){
  cin>>t;
  while(t--){
    cin >> n;

    Trie *root = new Trie;
    bool result = true;

    for(int i = 0; i<n; i++){
      cin>>number;
      if(result && root->insert(number))
        result = false;
    }
    if(result)
    printf("YES\n");
    else
    printf("NO\n");
    delete root;
    }
}
