input();a=input()[::2];p=10
for c in'><':
 r=[];s=a+c
 while s:i=s.find(s[-1])+1;r+=map(abs,range(p-i,p));p-=i;s=s[i:]
 print(*r,sep='');p=1