#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int T, N, M, num, maxi, count = 0, max = 0;
    queue<int> q;
    map<int, int> m; 
    cin >> T;
    for(int i = 0; i < T; i ++) 
    {
        cin >> N >> M;
        for(int j = 0; j < N; j++)
        {
            cin >> num;
            q.push(num);
            if(j == M) m[num] = 1;
            else m[num] = 0;
        }
        for(int j = 0; j < N; j++)
        {
            num = q.front();
            q.pop();
            q.push(num);
            if(max < num) 
            {
                maxi = j;
                max = num;
            }
        }
        for(int k = 0; k < N; k++)
        {
            for(int j = 0; j < maxi; j ++)
            {
                num = q.front();
                q.pop();
                q.push(num);
            }
            q.pop();
            if(m[q.front()]) 
            {
                cout << count << "\n";
                break;
            }
            else count++;
        }
    }
    return 0;
}
-----
1. map<int,int> m; 으로 target 위치 저장하려 했는데, 똑같은 중요도 값이 여러 개 들어오면 덮어써버림. 그래서 target 구분이 안 됨.
2. count 변수는 테스트케이스마다 초기화 안 하고 계속 누적됨.
-----

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int,int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            q.push({num, i});
            pq.push(num);
        }

        int count = 0;
        while (!q.empty()) {
            int a = q.front().first;
            int index = q.front().second;
            q.pop();

            if (a == pq.top()) {
                pq.pop();
                count++;
                if (index == M) {
                    cout << count << "\n";
                    break;
                }
            } else {
                q.push({a, index});
            }
        }
    }
    return 0;
}
-----
  새로 배운 점!
  priority_queue(우선순위 큐): 자동으로 내림차순으로 정리 >> 하나씩 제거해 가면서 최댓값을 비교해 찾는다.
  pair: 큐를 2차원으로 사용 가능하게 만듬 queue 사용시 STL은 따로 정의 필요 X
