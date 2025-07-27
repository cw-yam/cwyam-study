# Day 1: C++ 포인터와 참조 개념 정리
-포인터, 참조자, nullptr, const 키워드 개념과 사용법에 대해 공부하고 정리한 내용입니다.  

## 포인터 (Pointer)

```cpp
int num = 7;
int* p1 = &num;

*p1 == num;  // *p1은 p1이 가리키는 값을 의미 → 7
```

- int* p1: 정수형 포인터 선언

- &num: num의 주소값

- *p1: 포인터가 가리키는 실제 값

### ❗ 잘못된 예시:

```cpp
int* p1 = num; // ❌ 정수 값을 포인터에 대입하면 오류
```

---

## 📌 참조 (Reference)
```cpp
int num = 7;
int& p2 = num;
```
- 참조는 변수의 또 다른 이름 (alias)

- num == p2 항상 성립

- 같은 메모리 공간을 공유함

### ❗ 반드시 선언과 동시에 초기화해야 함

```cpp
int& ref;       // ❌ 오류
int& ref = num; // ✅ 가능
```

---

## 📌 nullptr
```cpp
int* ptr = nullptr;
```

- 포인터가 아무 것도 가리키지 않음을 명시할 때 사용

- 이전에는 NULL을 썼지만, nullptr이 더 안전함

---

## 📌 const
### 값 상수화
```cpp
const int x = 10;
x = 20; // ❌ 수정 불가
```

### 포인터 관련 const
```cpp
int val = 5;

const int* ptr1 = &val;     // *ptr1 값 수정 불가
int* const ptr2 = &val;     // ptr2 주소 수정 불가
const int* const ptr3 = &val; // 값과 주소 모두 수정 불가
```

선언 형태	| 의미
:---|:---
`const int* p`|값 수정 불가 (*p = ... ❌)
`int* const p`|주소 수정 불가 (p = ... ❌)
`const int* const p`|값도 주소도 수정 불가


## ✅ 요약 정리

개념|설명
:---|:---
`int* p = &x;`|포인터: 주소 저장
`int& r = x;`|참조자: 동일 주소 공유
`nullptr`|비어 있는 포인터 표현
`const`|값/주소의 변경 방지

---

```cpp
int num = 7;  
int *p1 = num; // *p1를 생성하는 순간 p1는 주소값 만을 담는 것으로 생성된 것.
```

- 선언만 해도 가능. (nullptr)

```cpp
int&p2 = num; // &p2를 생성하는 순간 num == p2 && p2 == num 이 항시 성립.
```
- 같은 주소값을 사용한다고 이해하는 것이 더 정확.  
- 초기화 필수.
 
 nullptr 포인터 변수를 초기화 할때 사용.  
 const 상수화 할때 사용.  
