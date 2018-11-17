#include<iostream>
#include<vector>
using namespace std;

int t, n;

vector<bool> check;//boolean 벡터 체크 생성
vector<pair<int, int> > v;//좌표를 표시해줄 클래스를 만들어 주고 x,y좌표를 벡터로 묶어줍니다.

//x좌표를 절대값으로 바꿔줍니다.
int abs(int x){
    return (x < 0 ? -x : x);
}

  //x와 y의 차이를 절대값으로 만들어 더해주고 1000보다 작거나 같을시에 참으로 반환해줍니다.
  //벌텍스 사이의 거리가 1000이하로만 구성되어야 상근이가 행복하다,
  bool dist(int x1, int y1, int x2, int y2){
      return ((abs(x1 - x2) + abs(y1 - y2)) <= 1000 ? true : false);
  }

  void dfs(int now){
      check[now] = true;
      //check가 false다. -> 탐색을 안했다.
      //dist가 참이다. -> 1000이하이다.
      //그렇다면 다음걸로
      //만약 true가 될 수 없다면 전단계로 돌아와 다시 길을 탐색한다.
      //마지막 까지 도달하는 경우가 있다면 n+1이 참이 된다.
      //왜냐하면 v[n]번째와 v[n+1]번째를 검사함으로 n+1값이 참이되면 끝까지 이어져있다는 뜻이다.
      for (int i = 1; i < n + 2; i++)
          if (!check[i] && dist(v[now].first, v[now].second, v[i].first, v[i].second))
              dfs(i);
  }

  int main(void){
    //상근이 집의 좌표는 0,0
    //맥주는 한박스에 20개
    //50미터마다 한병씩 소비
    //만약 편의점을 들린다면 새 맥주병 구입 가능
    //하지만 최대 20개까지 가능
    //락 페스티벌 좌표

    //편의점 개수가 주어진다. 0~100
    //상근이네 집 좌표 주어진다
    //편의점 좌표 받아온다.
    //락페스티벌 좌표 받아온
    //좌표사이의 거리는 x1-x2 + y1-y2
      cin >> t;
      while (t--){
          cin >> n;

          //벡터 check는 n+2개의 false값을 갖는다.
          //n개의 convinece store와 집+페스티벌 = n+2
          check = vector<bool>(n + 2, false);

          //n+2개의 좌표 값을 갖는다.
          v = vector<pair<int, int> >(n + 2, make_pair(0, 0));

          //좌표값을 입력 받는다.
          for (int i = 0; i < n + 2; i++)
              cin >> v[i].first >> v[i].second;

          //설정된 값을들 깊이 우선 탐색으로 검사 시작
          dfs(0);
          //check[n+1]번째 즉 락페스티발과 마지막 한개의 편의점이라도 연결되어 true가 된다면 happy
          cout << (check[n + 1] ? "happy" : "sad") << "\n";
      }
      return 0;
  }
