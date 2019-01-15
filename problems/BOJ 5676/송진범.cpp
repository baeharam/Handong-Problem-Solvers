#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segmentTree{
        int n;
        vector<long long> pMult;
        segmentTree(const vector<long long> &array){
             n = array.size();
             pMult.resize(n * 4);
             init(array, 0, n - 1, 1);
        }
          long long init(const vector<long long> &array, int left, int right, int node){
                 if (left == right)
                         return pMult[node] = array[left];
                 int mid = (left + right) / 2;
                 long long leftSubTree = init(array, left, mid, node * 2);
                 long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);

                 return pMult[node] = (leftSubTree*rightSubTree);
        }

        long long query(int left, int right, int node, int nodeLeft, int nodeRight){
                 if (right < nodeLeft || nodeRight < left)
                         return 1;
                 if (left <= nodeLeft && nodeRight <= right)
                         return pMult[node];
                 int mid = (nodeLeft + nodeRight) / 2;
                 return query(left, right, node * 2, nodeLeft, mid)*query(left, right, node * 2 + 1, mid + 1, nodeRight);
        }

        long long query(int left, int right){
                 return query(left - 1, right - 1, 1, 0, n - 1);
        }
        long long update(int index, int newValue, int node, int nodeLeft, int nodeRight){
                 if (index < nodeLeft || nodeRight < index)
                         return pMult[node];
                 if (nodeLeft == nodeRight)
                         return pMult[node] = newValue;
                 int mid = (nodeLeft + nodeRight) / 2;
                 return pMult[node] = update(index, newValue, node * 2, nodeLeft, mid)*update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
        }
        long long update(int index, int newValue){
                 return update(index - 1, newValue, 1, 0, n - 1);
        }
};

int main(void){
        int N, K;
        while(cin >> N)
        {
                 cin >> K;
                 vector<long long> v(N);
                 for (int i = 0; i < N; i++)
                 {
                     int temp;
                     cin >> temp;
                    if (temp > 0)
                       v[i] = 1;
                     else if (temp == 0)
                       v[i] = 0;
                     else
                       v[i] = -1;
                 }
                 segmentTree seg(v);
                 for (int i = 0; i < K; i++)
                 {
                         char op;
                         int a, b;
                         cin >> op >> a >> b;
                         if (op == 'C')
                         {
                                 if (b > 0){
                                        seg.update(a, 1);
                                        v[a - 1] = 1;
                                 }
                                 else if (b == 0){
                                        seg.update(a, 0);
                                        v[a - 1] = 0;
                                 }
                                 else {
                                      seg.update(a, -1);
                                      v[a - 1] = -1;
                                 }
                         }
                         else {
                                 long long result = seg.query(a, b);
                               if (result > 0)
                                    cout << '+';
                               else if (result == 0)
                                    cout << '0';
                               else
                                    cout << '-';
                         }
                 }
                 cout << "\n";
        }
        return 0;
}
