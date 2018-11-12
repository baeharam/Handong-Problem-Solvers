#include<stdio.h>
#pragma warning(disable : 4996)
int number(int num);

int main(void)
{
	int cate[11] = { 0 };
	int num, a = 0;

	printf("give T :");
	scanf("%d", &num);
	printf("give numbers ");

	for (int i = 0; i < num; i++){
		scanf("%d", &a);
		cate[i] = number(a);
	}
	for (int i = 0; i < num; i++)
		printf("%d ", cate[i]);

	system("pause");
	return 0;
}

int number(int num) {
	int dp = 0;

	if (num <= 0)
		return 0;
	if (num == 1)
		return 1;
	if (num == 2) 
		return 2;
	if (num == 3) 
		return 4;
	
	for(int i = 4; i <= num; i++)
		dp = number(i - 1) + number(i - 2) + number(i - 3);
	return dp;
}