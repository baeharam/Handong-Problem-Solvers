#include <iostream>
#include <stdio.h>
using namespace std;

int count_sum(int temp, int sum);//count the numbers of sum

int main(int argc, char const *argv[]) {

  int sum_count = 0;//user's input
  int check = 0;

  while(check != EOF)
  {
    cout<<"please enter the integer(1~10) : ";
    check = scanf("%d", &sum_count);

    cout<<"The number of all methods is "<< count_sum(0, sum_count)<<"\n\n";
  }

  return 0;
}

int count_sum(int temp, int sum)
{
  //there is only 1~3 ints exist.
  //so let's start easy level. that is 1.
  //1 has only one answer. that is 1. let's think next level
  //2 has 1+1 or 2. there is two ways.
  //3 has 1+1+1, 1+2, 2+1, 3. there is four ways.
  //let's think next level
  //4 has 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 3+1, 1+3. there is 7 ways.
  //4's count 7 is same with add 1, 2 and 3's count.
  //so 5 has 1+2+4+7 = 14? no answer is 13. one's count is omitted.
  //so n's count = (n-1)+(n-2)+(n-3)'s count
  //we can solve problem with recurscive function.
  if(temp > sum)//if sum is less than temp that value is useless
    return 0;

  if(temp == sum)//if tmpe = sum we find answer
    return 1;
    //The function does not decline the number it receives.
    //Start at 0 and rise until the entered value is input.
    //time complexity is n-1
  return count_sum(temp+1, sum) + count_sum(temp+2, sum) + count_sum(temp+3, sum);
}
