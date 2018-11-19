#include <iostream>
#include <algorithm>

using namespace std;

int canvasSize;
bool canvas[64][64];

void consoleInput(){
  scanf("%d", &canvasSize);
  for (int i = 0; i < canvasSize; i++)
  {
    for (int j = 0; j < canvasSize; j++)
    {
      char tmp = getchar();
      if(tmp == '\n')
      {
        j--;//사용자가 enter를 입력하면 자동으로 i는 늘어나고 j를 다시 재조정해준다.
        continue;
      }

      if(tmp - '0' == 0)//입력 받는 값이 0이면 false
        canvas[i][j] = false;

      else
        canvas[i][j] = true;
    }
  }
}

int isSameColor(int i_start, int i_end, int j_start, int j_end){

  bool nowColor = canvas[i_start][j_start];

  for (int i = i_start; i < i_end; i++)
  {
    for (int j = j_start; j < j_end; j++)
    {
      if (nowColor != canvas[i][j])
      {
        return -1;
      }
    }
  }
  return (int)nowColor;
}

void solve(int i_start, int i_end, int j_start, int j_end)
{
  int color = isSameColor(i_start, i_end, j_start, j_end);
  if (color != -1)
  {
    cout << color;//모두 다 같은 색이면 그냥 출력
  }

  else
  {
    cout << "(";
    int length = (i_end - i_start) / 2;

    for (int i = i_start; i < i_end; i += length )
    {
      for (int j = j_start; j < j_end; j += length )
      {
        solve(i, i + length, j, j + length);
      }
    }
    cout << ")";
  }
}

int main(){
  consoleInput();
  solve(0, canvasSize, 0, canvasSize);
  cout << endl;
  return 0;
}
