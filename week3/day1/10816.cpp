#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<int, int> m;
    int num, count;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        if(m[num] > 0) m[num] ++;
        else m[num] = 1;
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> num;
        cout << m[num] << " ";
    }
    return 0;
}

--------------
 시간초과로 인한 실패
  1. map사용을 unordered_map으로 수정을 통한 속도 향상.
  2. ios::sync_with_stdio(false); cin.tie(nullptr); 사용을 통한 입출력 속도 향상.
--------------
  map보다 unordered_map 빠른 이유는 map은 내부구조가 이진탐색트리로 항상 오름차순 정렬을 유지하고
  속도는 O(log N)을 유지하는 반면 unordered_map은 내부구조가 해시 테이블 구조로 이루어져 정렬이 안된 상태로
  원하는 값을 해시값을 통해 바로 접근 할 수 있다 평균 속도는 O(1)으로 압도적으로 빠르다. 하지만 메모리를 많이 차지한다..
--------------

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<int, int> m;
    int num;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        m[num] ++;
    }
    
    int M;
    cin >> M;
    
    for(int i = 0; i < M; i++)
    {
        cin >> num;
        cout << m[num] << " ";
    }
    return 0;
}
