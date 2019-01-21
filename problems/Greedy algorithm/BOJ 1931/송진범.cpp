#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time{
  int start;
  int end;
};

bool compare(Time t1, Time t2){
  if(t1.end == t2.end)
    return t1.start < t2.start;
  else
    return t1.end <t2.end;
}

int main(){
  int N;
  cin>>N;


  vector<Time> schedule(N);
  for(int i = 0; i<N;i++){
    cin>> schedule[i].start>>schedule[i].end;
  }

  sort(schedule.begin(), schedule.end(), compare);

  int count = 0;
  int save = 0;

  for(int i = 0; i< schedule.size();i++){
    if(save <=schedule[i].start){
      save = schedule[i].end;
      count++;
    }
  }
  cout << count<<endl;
}
