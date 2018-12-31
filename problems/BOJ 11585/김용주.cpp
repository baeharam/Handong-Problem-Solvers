//BOJ11585 Odsn
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 1000000

int n, pi[MAX_N];
char str1[MAX_N * 2], str2[MAX_N];

int main(){
	scanf("%d\n", &n);
	//원형이므로 string 2개를 이어붙이고 아래꺼로 위에꺼 비교.
	for(int i = 0; i < n; i++){
		scanf(" %c", &str1[i]);
		str1[n + i] = str1[i];
	}
	for(int i = 0; i < n; i++)
		scanf(" %c", &str2[i]);

	//실패함수.
	for(int i = 1, j = 0; i < n ; i++){
		while(j > 0 && str2[i] != str2[j])
			j = pi[j-1];
		if(str2[i] == str2[j])
			pi[i] = ++j;
	}

	//KMP
	int cnt = 0;
	for(int i = 0, j = 0; i < 2*n-1; i++){
		while(j > 0 && str1[i] != str2[j])
			j = pi[j-1];
		if(str1[i] == str2[j]){
			if(j == n-1){
				cnt++;
				j = pi[j];
			}
			else j++;
		}
	}

	//GCD(최대공약수)
	int a = n;
	int b = cnt;
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	n /= a;	cnt /= a;
 	printf("%d/%d", cnt, n);

	return 0;
}