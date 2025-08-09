#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v1(N), v2(N);
    for(int i = 0; i < N; i ++) cin >> v1[i];
    v2 = v1;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for(int i = 0; i < N; i++)
    {
        int count = 0;
        for(int j = 0; j < N; j++)
        {
            if(v1[i] == v2[j])
            {
                cout << count << " ";
                break;
            }
            else count ++;
        }
    }
    return 0;
}
-------------
  시간초과로 인한 실패
  이유: 최악의 경우에 O(N^2)의 시간이 걸려 오래 걸림
  해결법: lower_bound의 이분 탐색을 이용하여 시간 복잡도를 O(log N)으로 줄여 풀이
-------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v1(N), v2(N);
    for(int i = 0; i < N; i ++) cin >> v1[i];
    v2 = v1;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for(int i = 0; i < N; i++)
    {
        int pos = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
        cout << pos << " ";
    }
    return 0;
}
-------------
여기서 lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin() 는 이터레이터 이기 때문에 pos를 통해 정수 인덱스로 변환 !
