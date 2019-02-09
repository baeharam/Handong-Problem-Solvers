#include<iostream>
#include<vector>

using namespace std;

typedef struct box{
	int start;
	int end;
	int gap;
};

int main(){
	int N, K, D;
	long long low, high, mid, cnt;
	vector<box> boxs;
	box input;

	scanf("%d %d %d", &N, &K, &D);

	for(int i = 0; i < K; i++){
		scanf("%d %d %d", &input.start, &input.end, &input.gap);
		boxs.push_back(input);
	}

	low = 1;
	high = N;

	while(low + 1 <high) {
		mid = (low + high / 2);
		cnt = 0;
		for(int i = 0; i < boxs.size(); i++){
			if(boxs[i].end < mid){
				cnt += (boxs[i].end - boxs[i].start)/boxs[i].gap+1;
			}

			else if(boxs[i].start > mid)
				continue;

			else if(boxs[i].start == mid)
				cnt += 1;

			else {
				cnt += (mid - boxs[i].start)/boxs[i].gap+1;
			}
		}

		if(cnt >= D){
			high = mid;
		}

		else
			low = mid;
	}

	printf("%lld\n", high);

	return 0;
}
