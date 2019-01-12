#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> phone;
string s;
int n,tc;
bool bigger,match;

int main(void)
{
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>s;
            phone.push_back(s);
        }

        sort(phone.begin(),phone.end());

        for(int i=0; i<n; i++){
            int l=i+1, r=n-1;

            while(l<=r){
                int m = (l+r)/2;
                bigger = false, match = true;
                for(int j=0; j<phone[i].length(); j++){
                    if(phone[i][j]<phone[m][j]){
                        bigger = true;
                        match = false;
                        break;
                    }
                    else if(phone[i][j]>phone[m][j]){
                        match = false;
                        break;
                    }
                }
                if(match) {
                    puts("NO");
                    break;
                }
                if(bigger) r = m-1;
                else if(!bigger) l = m+1;
            }
            if(match) break;
        }
        if(!match)puts("YES");
        phone.clear();
    }
    return 0;
}