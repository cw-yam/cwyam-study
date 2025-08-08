# vector, set의 활용

## 📌 실습 미션 1 : 정수 N개를 입력받아 벡터에 저장한 뒤, 역순으로 출력해보기.

```md
입력: 5  
1 3 5 7 9  
출력: 9 7 5 3 1
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> vec; // vec(N)으로 생성하는 것이 더 메모리에 효율적임!
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    } // cin >> vec[i] 하면 한줄 요약 가능!
    sort(vec.begin(), vec.end()); // 뒤에 greater<int>() 추가시 reverse 안써도 가능!
    reverse(vec.begin(), vec.end());
    for(int x : vec) cout << x << " "; // auto를 쓰면 가독성 향상!
    return 0;
}
```

## 📌 실습 미션 2 : 중복 제거 후 정렬

```md
입력: 8
5 3 5 2 3 9 1 9
출력: 1 2 3 5 9
```

## vector 버전
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);

    for (int i = 0; i < N; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end()); // 중복 제거의 표준 코드임!

    for (auto x : vec) cout << x << ' ';
}

```

## set 버전
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> s;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    for (auto x : s) cout << x << ' ';
}
```

## 실습 미션 3 : 교집합 구하기

```md
입력: 5 4
1 3 5 7 9
3 5 6 7
출력: 3 5 7
```

```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    set<int> A, B, answer;
    for(int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        A.insert(x);
    }
    for(int i = 0; i < b; i++)
    {
        int y;
        cin >> y;
        B.insert(y); // 쓰레기 값.
        if(A.count(y) == true) // A.count(y)는 0 또는 1이므로 true 생략 가능!
        {
            answer.insert(y);
        }
    } // set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(answer, answer.begin()));로 한줄 처리 가능!
    for(auto Q : answer) cout << Q << " ";
}
```
