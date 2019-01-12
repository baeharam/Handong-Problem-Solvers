#include <cstdio>
#include <cstring>
using namespace std;

const int Max = 100001;

struct Trie{
    int cnt;
    int go[Max][11];    // 다음 노드 번호를 가지고 있는 2차원 배열
    bool output[Max];   // 노드에서 끝나는 전화번호가 있는지
    bool goexist[Max];  // 노드의 자식 확인

    Trie(){
        cnt = 1;
        memset(output, 0, sizeof(output)); 
        memset(go, 0, sizeof(go));  
        memset(goexist, 0, sizeof(goexist)); // 모두 0으로 초기화
    }

    bool insert(const char* key, int node = 0){
        if(*key == '\0'){ // key가 null 일때
            output[node] = true;    // 전화번호 끝에 또 자식이 있으면 있으면 true
            return !goexist[node];          // 일관성이 없다
        }
        // 이 부분에서는 이해가 안됬다 -> 자식이 있었는데 여기서 끝나는 전화번호가 있으면 일관성이 없다...
        int next = *key - '0';
        if(!go[node][next]) go[node][next] = cnt++;
        goexist[node] = true;
        return !output[node] && insert(key+1, go[node][next]);
    }
};
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        Trie trie;
        bool flag = true;
        for(int i = 0; i < n; i++){
            char tel[11];
            scanf("%s", tel);
            if(flag && !trie.insert(tel)) flag = false;
        }
        puts(flag ? "YES" : "NO");
    }
}
