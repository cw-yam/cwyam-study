#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, X, count = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X;
        bool T = true;
        if(X == 1) T = false;
        for(int j = 2; j < X; j ++) {
            if(X % j == 0) {
                T = false;
                break;
            }
        }
        if(T) count ++;
    }
    cout << count;
    return 0;
}
--------------------------
더 효율적인 풀이 - 루트 X 까지만 비교해서 최적화
--------------------------
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, X, count = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X;
        bool T = true;
        if(X == 1) T = false;
        for(int j = 2; j * j <= X; j ++) {
            if(X % j == 0) {
                T = false;
                break;
            }
        }
        if(T) count ++;
    }
    cout << count;
    return 0;
}
--------------------
에라토스테네스의 체 - 1 부터 N 까지의 수 중에서 소수만 남기고 다 지우는 방식
--------------------
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false; 

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) cout << i << " ";
    }

    return 0;
}
