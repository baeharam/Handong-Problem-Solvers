#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char sign[9]; //2<=k<=9

vector<int> v_max;
vector<int> v_min;

bool compareSign(vector<int> v, int size){
  for(int i=0; i<size; i++){
    if(sign[i] == '<' && v[i]>v[i+1])
    return false;
    if(sign[i] == '>' && v[i]<v[i+1])
    return false;
  }

  return true;
}

void max(vector<int> v_max, int size){
  for(int i=9; i>9-(size+1); i--){  //큰수부터 push
    v_max.push_back(i);
  }
  while(compareSign(v_max, size) == false){ 
    //부등호에따라 크기가 만족하지 못하면 이전순열로 재배열 ex)987->978
    prev_permutation(v_max.begin(),v_max.end());
  }

  // for(int i : v_max)
  //   cout<<i;
  for(int i=0; i<v_max.size(); i++)
    cout<<v_max[i];

  cout<<endl;
}

void min(vector<int>v_min, int size){
  for(int i=0; i<size+1; i++){
    v_min.push_back(i);
  }
  while(compareSign(v_min, size) == false){
    //부등호에 따라 크기가 만족하지 못하면 다음순열로 재배열 ex)123->132
    next_permutation(v_min.begin(), v_min.end());
  }

  // for(int i : v_min)
  //   cout<<i;
  for(int i=0; i<v_min.size(); i++)
    cout<<v_min[i];

}

int main(){
  int k;
  cin>>k; //2<=k<=9

  //부등호 입력받아 array에 push
  for(int i=0; i<k; i++){
   cin >> sign[i];
  }

  max(v_max, k);
  min(v_min, k);

	return 0;
}
