#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int M = N, d = 0;
    while(M)
    {
        M /= 10;
        d++;
    }
    
    int answer = 0;
    for(int i = max(1, N - 9*d); i < N; i ++)
    {
        int x = i;
        string a = to_string(i);
        for(int j = 0; j < a.length(); j++) x += a[j] - '0';
        
        if(N == x) 
        {
            answer = i;
            break;
        }
    }
    cout << answer;
    return 0;
}
----------
분해합을 구하는 방법: 주어진 수 + 주어진 수의 각 자리 수의 합
생성자를 구해야 하기 때문에 주어진 수의 자리수를 구한다음 자리수에 9를 곱한 값을 
  주어진 수에서 뺀 것부터 주어진 수까지가 경우의 수가 될 수 있음.
  (N의 생성자 구하는 법: N - N의 자리수 * 9 ~ N 사이를 구해서 비교해보기)
