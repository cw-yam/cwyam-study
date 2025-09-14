#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    string N;
    cin >> N;
    for(int i = 0; i < N.length(); i++)
    {
        int x = stoi(N[i]);
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N.length(); i++) cout << v[i];
    return 0;
}
----------
  N[i]가 char형이라서 string >> int 로 가는 stoi는 사용 불가.
  대신 int x = N[i] - '0'을 해주면 정상 처리가능
  +내림차순 출력이기 때문에 sort 뒤에 greater<int> ()을 추가해 줘야 함!

----------
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    string N;
    cin >> N;
    for(int i = 0; i < N.length(); i++)
    {
        int x = N[i] - '0';
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < N.length(); i++) cout << v[i];
    return 0;
}
