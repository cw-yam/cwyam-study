# STL 공부

## 요약본

```md
0. iostream
cin : 표준 입력 스트림

cout : 표준 출력 스트림

wcin, wcout : wide character 입출력 (유니코드 문자 지원)
```

```md
1. vector
push_back(value) : 벡터 끝에 원소 추가

pop_back() : 벡터 끝 원소 제거

size() : 벡터 내 원소 개수 반환

clear() : 모든 원소 삭제

[] 연산자 : 인덱스 접근
```

```md
2. cwchar
wchar_t : wide character 타입

wcslen() : wide string 길이 반환

기타 wide string 관련 함수들 (wcscpy(), wcsncmp() 등)
```

```md
3. string
length() 또는 size() : 문자열 길이 반환

substr(pos, len) : 부분 문자열 반환

append(), push_back() : 문자열 뒤에 문자 추가

find() : 특정 문자나 문자열 위치 검색
```

```md
4. algorithm
sort(begin, end) : 정렬 (기본 오름차순)

max_element(begin, end) : 구간 내 최댓값 찾기

min_element(begin, end) : 구간 내 최솟값 찾기

reverse(begin, end) : 구간 뒤집기

lower_bound(begin, end, value) : 정렬된 구간에서 이분 탐색으로 값 위치 찾기
```

```md
5. cmath
pow(base, exponent) : 제곱 계산

sqrt(value) : 제곱근 계산

round(value) : 반올림

abs(value) : 절댓값

sin(), cos(), tan() : 삼각 함수
```

```md
6. stack
push(value) : 스택에 원소 추가

pop() : 최상단 원소 제거

top() : 최상단 원소 반환

empty() : 스택이 비었는지 확인
```

```md
7. queue
push(value) : 큐에 원소 추가

pop() : 가장 앞 원소 제거

front() : 가장 앞 원소 반환

back() : 가장 뒤 원소 반환

empty() : 큐가 비었는지 확인
```

```md
8. deque
push_back(value) : 뒤에 원소 추가

push_front(value) : 앞에 원소 추가

pop_back() : 뒤 원소 제거

pop_front() : 앞 원소 제거

front() : 앞 원소 반환

back() : 뒤 원소 반환

empty() : 덱이 비었는지 확인

size() : 덱 크기 반환
```

```md
9. map
insert(pair) : 키-값 쌍 삽입

operator[] : 키로 값 접근 및 삽입

erase(key) : 키에 해당하는 원소 삭제

find(key) : 키를 가진 원소 찾기 (iterator 반환)

count(key) : 키 존재 여부 반환 (0 또는 1)
```

```md
10. set
insert(value) : 원소 삽입

erase(value) : 원소 삭제

find(value) : 원소 존재 여부 확인 (iterator 반환)

count(value) : 원소 존재 여부 반환 (0 또는 1)
```

---

# 예제

## 0. iostream : 기본 입출력
```cpp
#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "정수를 입력하세요: ";
    cin >> a;
    cout << "입력한 값은 " << a << "입니다.\n";
}
```

```md
정수를 입력하세요: 10
입력한 값은 10입니다.
```

## 1. vector : 동적배열
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{   
    vector<int> vec = {1, 2, 3};
    
    vec.push_back(4);
    vec.push_back(5);
    
    cout << "vector element: ";
    for(int x: vec) cout << x << " ";
    
    vec.pop_back();
    cout <<"\nafer pop_back: ";
    for(int x: vec) cout << x << " ";
    
    cout << "\nsize: " << vec.size();
    return 0;
}
```

```md
vector element: 1 2 3 4 5 
afer pop_back: 1 2 3 4 
size: 4
```

---

## 2. cwchar : 영어 ASCLL 외 언어 사용 가능하게
```cpp
#include <iostream>
#include <cwchar>  // for wide-char functions
using namespace std;

int main() {
    wchar_t wstr[] = L"안녕하세요";
    wcout << L"문자 수: " << wcslen(wstr) << endl; // 리터널이 L이다!
}
```

```md
문자 수: 5
```

---

## 3. string : 문자열
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "이름 입력: ";
    cin >> name;

    cout << "안녕하세요, " << name << "님!\n";
    cout << "이름의 길이: " << name.length() << endl;
}
```

```md
이름 입력: cw_yam
안녕하세요, cw_yam님!
이름의 길이: 6
```

---

## 4. algorithm : 알고리즘
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {5, 1, 3, 4, 2};
    sort(v.begin(), v.end());

    cout << "오름차순 정렬: ";
    for (int x : v) cout << x << " ";

    cout << "\n최댓값: " << *max_element(v.begin(), v.end()) << endl;
}
```

```md
오름차순 정렬: 1 2 3 4 5 
최댓값: 5
```

---

## 5. cmath : 수학
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 2.5;
    cout << "제곱: " << pow(x, 2) << endl;
    cout << "루트: " << sqrt(x) << endl;
    cout << "반올림: " << round(x) << endl;
    cout << "절댓값: " << abs(-3) << endl;
}
```

```md
제곱: 6.25
루트: 1.58114
반올림: 3
절댓값: 3
```

---

## 6. stack : 후입선출
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
```

```md
30 20 10
```

---

## 7. queue : 선입 선출
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;
    q.push("apple");
    q.push("banana");
    q.push("cherry");

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
```

```md
apple banana cherry
```

---

## 8. deque : 덱(양쪽에 데이터 삽입 가능)
```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);

    for (int x : dq)
        cout << x << " ";
}
```

```md
2 1 3
```

## 9. map : 키 - 값
```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> m;
    m["apple"] = 3;
    m["banana"] = 2;

    for (auto pair : m)
        cout << pair.first << " : " << pair.second << "\n";
}
```

```md
apple : 3
banana : 2
```

---

## 10. set : 중복제거 및 정렬
```cpp
#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {3, 1, 4, 1, 2, 2};

    for (int x : s)
        cout << x << " ";
}
```

```md
1 2 3 4
```
