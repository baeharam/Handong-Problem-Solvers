#include <iostream>
#include <algorithm>
using namespace std;

  int N,C;
  int home[200000];
  int left, right;
  int result;

void binary_search(int left, int right){
  while(left<=right){
  //if(left<=right){
    int router =1;
    int middle = (left+right)/2;
    int prev = home[0];

    for(int i=1; i<N; i++){
      if(home[i]-prev >= middle){
        router++;
        prev = home[i];
      }
    }
    if(router >= C){
      result = middle;
      //binary_search(left+1, right);
      left = middle+1;
    }
    else{
      //binary_search(left, right-1);
      right = middle-1;
    }
  }
}

int main() {
  cin>>N>>C;
  for(int i=0; i<N; i++){
    cin>>home[i];
  }

  sort(home, home+N);
  binary_search(1, home[N-1]);

  cout<<result;
}
