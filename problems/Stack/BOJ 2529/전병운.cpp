#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//그리디 알고리즘 사용-> 최대 최솟값 고정
//순열 사용 -> 알고리즘
//최대 값과 최소 값을 미리 선별한 후 sort를 진행한다.
bool check(vector<char> & _sign, vector<int> & num)
{
    for (int i = 0; i < _sign.size(); ++i)
    {
        if (_sign[i] == '>' && num[i] < num[i + 1])
            return false;

        if (_sign[i] == '<' && num[i] > num[i + 1])
            return false;
    }
    return true;
}

int main()
{
    //부등호를 받아 줄 벡터 사인
    vector<char> sign;
    //가장 큰 숫 벡터
    vector<int> num_max;
    //가장 작은 숫자 벡터
    vector<int> num_min;

    int input;
    cin >> input;
    for (int i = 0; i < input; ++i)
    {
        char t_input;
        cin >> t_input;
        sign.push_back(t_input);
    }

    //최대값
    for (int i = 9; i >= 9 - input; --i)
        num_max.push_back(i);
    //최소값
    for (int i = 0; i <= input; ++i)
        num_min.push_back(i);

    //최대값에서 순열을 시작하여 조건을 만족할때까지 찾습니다.
    do
    {
        if (check(sign, num_max))
            break;
    } while (prev_permutation(num_max.begin(), num_max.end()));
    //최소값에서 순열을 시작하여 조건을 만족할때까지 찾습니다.
    do
    {
        if (check(sign, num_min))
            break;
    } while (next_permutation(num_min.begin(), num_min.end()));

    for (int i = 0; i < num_max.size(); ++i)
        cout << num_max[i];

    cout << endl;

    for (int i = 0; i < num_min.size(); ++i)
        cout << num_min[i];

    cout << endl;

    return 0;
}
