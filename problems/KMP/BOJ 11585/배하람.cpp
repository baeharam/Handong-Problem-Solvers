#include <cstdio>
#include <vector>
using namespace std;

vector<int> f,r;
vector<char> roul1,roul2;

int failure_function(const vector<char>& s)
{
    int n = s.size();
    f.resize(n);
    int begin=1, m=0;

    while(begin < n){
        if(s[begin+m]==s[m]){
            m++;
            f[begin+m-1] = m;
        } else{
            if(m==0) begin++;
            else{
                begin += (m-f[m-1]);
                m = f[m-1];
            }
        }
    }
    return n/(n-f[n-1]);
}

int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(void)
{
    int a;
    scanf("%d",&a);
    roul1.resize(a);
    roul2.resize(a);
    for(int i=0; i<a; i++) scanf(" %c",&roul1[i]);
    for(int i=0; i<a; i++) scanf(" %c",&roul2[i]);

    int b = failure_function(roul1);
    int g = gcd(a,b);
    printf("%d/%d",b/g,a/g);
    return 0;
}