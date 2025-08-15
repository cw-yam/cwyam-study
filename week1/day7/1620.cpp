#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main()
{
    int M, N;
    string s;
    cin >> M >> N;
    map<int, string> m;
    map<string, int> m2;
    for(int i = 0; i < M; i ++)
    {
        cin >> s;
        m[i + 1] = s;
        m2[s] = i + 1;
    }
    for(int i = 0; i < N; i ++)
    {
        cin >> s;
        if(isdigit(s[0])) cout << m[stoi(s)] << "\n";
        else cout << m2[s] << "\n";
    }
    return 0;
}

---------------
  시간초과로 인한 실패 >> ios::sync_with_stdio(false);  cin.tie(NULL); 을 통해 해결
1. ios::sync_with_stdio(false);
  C++의 cin/cout과 C의 scanf/printf를 동기화 해제하는 명령.

  기본적으로는 동기화가 켜져 있어서 속도가 느린데,
  동기화를 끄면 C++ 표준 입출력이 훨씬 빨라져.

  대신, 동기화를 끄면 cin/cout과 scanf/printf를 섞어 쓰면 안 돼.
    
2. cin.tie(NULL);

  cin과 cout을 묶어둔 버퍼 플러시 연결을 끊는 명령.

  기본적으로 cin을 쓰기 전에 cout이 자동으로 flush(출력 버퍼 비움)되는데,
  이걸 끊으면 불필요한 flush가 사라져서 속도가 더 빨라짐.  - <chat GPT와의 대화 중>

입력 크기가 커질 수록 속도 차이가 커짐!
[시각화]
    <미사용시>
  [키보드 입력] → [C 버퍼] ↔ [C++ 버퍼] → 프로그램 cin
                               ↑
                            동기화(O)

    <사용시>
  [키보드 입력] → [C++ 버퍼] → 프로그램 cin
    (C 버퍼 무시, 동기화 해제)
    -------------
수정 버전

#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M, N;
    string s;
    cin >> M >> N;
    map<int, string> m;
    map<string, int> m2;
    for(int i = 0; i < M; i ++)
    {
        cin >> s;
        m[i + 1] = s;
        m2[s] = i + 1;
    }
    for(int i = 0; i < N; i ++)
    {
        cin >> s;
        if(isdigit(s[0])) cout << m[stoi(s)] << "\n";
        else cout << m2[s] << "\n";
    }
    return 0;
}

--------------
추가 정보 - vector을 통해 int - string을 출력하고 unorder_map을 통해 string - int를 출력하면 더 빠르다 !

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<string> num_to_name(M + 1);
    unordered_map<string, int> name_to_num;

    string s;
    for (int i = 1; i <= M; i++) {
        cin >> s;
        num_to_name[i] = s;
        name_to_num[s] = i;
    }

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (isdigit(s[0])) {
            cout << num_to_name[stoi(s)] << "\n";
        } else {
            cout << name_to_num[s] << "\n";
        }
    }

    return 0;
}

---------------

[시각화]
번호 → 이름 : vector<string> num_to_name
Index: 1       2          3          4
Value: Pikachu Bulbasaur Charmander Squirtle

이름 → 번호 : unordered_map<string, int> name_to_num
Key:    Pikachu    Bulbasaur   Charmander   Squirtle
Value:      1          2           3           4

--------------
  추가로 인지할 점: isdigit(char) - 정수인지 판단
