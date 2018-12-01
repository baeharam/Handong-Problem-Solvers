#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int h_n, c_n, count;
	int temp = h_n-2;
	scanf("%d", &h_n);
	scanf("%d", &c_n);
	int arr[h_n], arr2[h_n-1];
	for(int i = 0; i < h_n;i++){
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+h_n);
	
	for(int i = 0; i < h_n-1; i++){
		arr2[i]= arr[i+1] - arr[i];
	}
	
	sort(arr2, arr2+temp);
	
	int distance = arr[h_n-1] - arr[0];
	int avg = distance/c_n;
	for(int j = c_n-1;j >= 0; j--){
		if(arr2[temp] >= avg) arr2[temp] = 0;
		else count++;
		temp--;
	}
	
	while(count != c_n){
		arr2[temp] = 0;
		temp--;
		count++;
	}
	printf("%d", max_element(arr2, arr2+temp));
}
