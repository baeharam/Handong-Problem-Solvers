#include <iostream>
using namespace std;

int N;
char pixel[64][64];

//array에 push하기
void push(){
  cin >> N;
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
       cin >> pixel[i][j];
    }
  }
}

//픽셀 색깔 체크
bool checkColor(int a, int b, int size){

  for(int i=b; i<b+size; i++){
    for(int j=a; j<a+size; j++){
      if(pixel[b][a] != pixel[i][j])  //다를경우
       return false;
    }
  }
  return true;    //같을경우
}

//압축하기
void compression(int a, int b, int size){
  bool same = checkColor(a, b, size);

  if(same == true) cout<<pixel[b][a];    //같으면 그냥출력
  else{
    cout << "(";

     if(size > 0){
     compression(a, b, size/2);         
     compression(a+size/2, b, size/2);  
     compression(a, b+size/2, size/2);
     compression(a+size/2, b+size/2, size/2);

     cout << ")";
    }
  }
}

int main() {
  push();
  compression(0,0,N);
    
  return 0;
}
