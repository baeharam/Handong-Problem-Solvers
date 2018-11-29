#include "iostream"
#include "cstdio"
using namespace std;

#define MAX 200000
void recursive_qsort(int arr[], int left, int right);
int arr[MAX];

int main(int argc, char const *argv[]) {
  int N, C;

  cin>>N>>C;

  for(int i=0; i<N;i++)
  {
    cin>>arr[i];
  }
  //퀵소트로 어레이 소팅
  recursive_qsort(arr, 0, N-1);

  //최소거리
  int min = 1;
  //최대거리
  int max = (arr[N-1] - arr[0]);
  //결과값
  int result;

  while(min <= max)
  {
    int mid = (min+max)/2;
    //기준점을 잡는순간 한개는 이미 설치
    int count = 1;
    int start = arr[0];

    for(int i=1;i<N;i++)
    {
      //비교대상과의 거리가 중간값보다 크거나 같을때
      if(arr[i] - start >= mid)
      {
        count++;
        start = arr[i];
      }
    }
    if(count >= C)
    {
      result = mid;
      min = mid+1;
    }
    else
      max = mid-1;
  }

  cout<<result;

  return 0;
}

void recursive_qsort(int arr[], int left, int right){
  if(left >= right)
    return;

  int pivot = arr[left];
  int i = left+1;
  int j = right;
  int temp;

  while(i <= j)
  {
    while(arr[i]<pivot)
      i++;
    while(arr[j]>pivot&& j>left)
      j--;

    if(arr[i]>pivot && arr[j]<pivot && i<=j)
    {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[left];
  arr[left] = arr[j];
  arr[j] = temp;

  recursive_qsort(arr, left, j-1);
  recursive_qsort(arr, j+1, right);
}
