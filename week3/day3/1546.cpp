#include <iostream>
using namespace std;

int main()
{
    int N, Max = 0;
    double arr[1000], Sum = 0;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        Max = arr[i] > Max ? arr[i] : Max;
    }
    for(int i = 0; i < N; i++)
    {
        arr[i] = arr[i]/Max*100;
        Sum += arr[i];
    }
    cout << Sum/N;
    return 0;
}
---------
  #include <algorithm> 사용
 삼항연산자에 의한 계산을 max_element(arr, arr+N)으로 사용
  
