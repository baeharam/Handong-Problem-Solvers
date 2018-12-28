#include<cstdio>
#define R(X) for(int X=0;X<N;X++)
int d[16][1<<16],c[16][16],N,I=1<<30;
int go(int n,int v){
	if(v==(1<<N)-1)return c[n][0]?c[n][0]:I;
	int t,&r=d[n][v];
	if(r)return r;r=I;
	R(i)if(!(v&(1<<i))&&c[n][i])t=(r,go(i,v|(1<<i))+c[n][i]),r=t<r?t:r;
	return r;
}
main(){
	scanf("%d",&N);
	R(i)R(j)scanf("%d",c[i]+j);
	return printf("%d",go(0,1)),0;
}