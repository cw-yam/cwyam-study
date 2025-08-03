#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<bool> vec(10000, true);
    for(int i = 1; i < 10000; i++)
    {
        string S = to_string(i);
        if(S.length() == 1) vec[i + i] = false;
        if(S.length() == 2) vec[i + i /10 + i % 10] = false;
        if(S.length() == 3) vec[i + i / 100 + ((i / 10) % 10) + i % 10] = false;
        if(S.length() == 4) vec[i + i / 1000 + ((i / 100)% 10) + ((i / 10)%10) + i % 10] = false;
    }
    for(int i = 0; i < 10000; i++)
    {
        if(vec[i]) cout << i << "\n";
    }
    return 0;
}
--------------
   답은 맞으나 개선 필요
  1. 계산 방법이 너무 복잡하여 깔끔히 바꿀 수 있음.
  2. vec에서 i가 9999라면 vec에서 10044로 벡터의 범위를 초과 할 수 있음.
--------------

#include <iostream>
#include <vector>
using namespace std;

int d(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    vector<bool> vec(10001, true);

    for (int i = 1; i < 10000; i++) {
        int dn = d(i);
        if (dn <= 10000) vec[dn] = false;
    }

    for (int i = 1; i < 10000; i++) {
        if (vec[i]) cout << i << "\n";
    }

    return 0;
}
