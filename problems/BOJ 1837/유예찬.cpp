// baekjoon 1837 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
const ll DIV_NUM=1000000000000LL; // 1e12
const int MAX_K=1000001;

bool visited[MAX_K];
char P[108];
ll K, data[9];

void convertP() {
	int Plen = strlen(P);
	int maxidx = (Plen-1)/12;
	int maxpad = (Plen-1)%12+1;
	for (int j=0; j<maxpad; j++) {
		data[maxidx]*=10ULL;
		data[maxidx]+=P[j]-'0';
	}

	for (int i=maxidx-1; i>=0; i--) {
		for (int j=0; j<12; j++) {
			data[i]*=10ULL;
			data[i]+=P[j+maxpad+(maxidx-1-i)*12]-'0';
		}
	}
}

void PrintData() {
	bool flag=true;
	for (int i=8; i>=0; i--) {
		if (!data[i] && flag) continue;
		flag=false;
		printf("%012lld", data[i]);
	}
	puts("");
}

bool divideData(ll x) {
	ll remain=0ULL;
	ll base=1;
	for (int i=0; i<9; i++) {
		remain=(remain+(base*(data[i]%x))%x)%x;
		base=(base*(DIV_NUM%x))%x;
	}
	return remain%x == 0;
}

int main() {
	scanf("%s %lld", P, &K);
	convertP();
	for (ll i=2; i<K; i++) {
		if (!visited[(int)i]) {
			if (divideData(i)) return !printf("BAD %lld\n", i);
			for (int j=i*i; j<K; j+=i) visited[j]=true;
		}
	}
	return !printf("GOOD\n");;
}

/* 짧은 코드 
// baekjoon 1837 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXK=1e6+1;

int k;
char p[101];
bool visited[MAXK];

bool isDivied(int x) {
	int ret=0;
	for (int i=0; p[i]; i++) ret=(ret*10+p[i]-'0')%x;
	return ret==0;
}

int main() {
	scanf("%s %d", p, &k);
	for (int i=2; i<k; i++) {
		if (!visited[i]) {
			if (isDivied(i)) return !printf("BAD %d\n", i);
			for (int j=i+i; j<k; j+=i) visited[j]=true;
		}
	}
	return !printf("GOOD\n");
}
*/