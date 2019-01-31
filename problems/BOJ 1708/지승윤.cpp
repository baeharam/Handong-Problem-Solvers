#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MAX 100002
typedef pair<int, int> Point;
typedef long long ll;
int N, stk[MAX], idx;
Point a[MAX];

int ccw(Point x, Point y, Point z){
	ll prd = 1LL * (y.X - x.X) * (z.Y - x.Y) - 1LL * (y.Y - x.Y) * (z.X - x.X);
	return (prd > 0 ? 1 : (prd < 0 ? -1 : 0));
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d %d", &a[i].X, &a[i].Y);
	}
	sort(a, a + N);
	sort(a + 1, a + N, [](Point &u, Point &v) {
		return atan2(u.Y - a[0].Y, u.X - a[0].X) < atan2(v.Y - a[0].Y, v.X - a[0].X);
	});
	stk[idx++] = 0, stk[idx++] = 1;
	for(int i = 2; i < N; i++){
		while(idx >= 2){
			if(ccw(a[stk[idx - 2]], a[stk[idx - 1]], a[i]) > 0)	break;
			idx--;
		}
		stk[idx++] = i;
	}
	printf("%d\n", idx);
	return 0;
}