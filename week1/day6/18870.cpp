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
-------------
-lower_bound()
    - 용도 : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
    - lower_bound의 반환형은 Iterator 이므로 실제로 몇 번째 인덱스인지 알고 싶다면
      위 코드와 같이 lower_bound 값에서 배열 첫 번째 주소를 가리키는 배열의 이름을 빼 주면 됩니다.
