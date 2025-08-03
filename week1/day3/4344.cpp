#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int C, N, sum = 0, count = 0;
    cin >> C;
    for(int i = 0 ; i< C; i++)
    {
        cin >> N;
        vector<int> vec(N + 1);
        for(int j = 0; j < N; j++)
        {
            cin >> vec[j];
            sum += vec[j];
        }
        
        double ss = sum / N;
        
        for(int j = 0; j < N; j++)
        {
            if(ss < vec[j]) count++; 
        }
        cout << round((double)count * 100000/N) / 1000 << "%\n";
        sum = 0;
        count = 0;
    }
    return 0;
}
-----------
  소수점 셋째자리 까지 표현하는 다른 방법!
  #include <iomanip> --> 출력 형식 조절 할 때 사용하는 헤더
  setprecision(3)

  ---------

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() 
{
    int C;
    cin >> C;

    while (C--) {
        int N;
        cin >> N;

        vector<int> vec(N);
        int sum = 0;
        for (int i = 0; i < N; i++) 
        {
            cin >> vec[i];
            sum += vec[i];
        }

        double avg = (double)sum / N;
        int count = 0;
        for (int i = 0; i < N; i++) 
        {
            if (vec[i] > avg) count++;
        }

        double rate = (double)count / N * 100;
        cout << fixed << setprecision(3) << rate << "%" << "\n";
    }

    return 0;
}
