#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{   
    int N;
    cin >> N;
    vector<pair<int, int>> v;
    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({y, x});
    }
    sort(v.begin(), v.end());
    for(auto p : v) cout << p.second << " " << p.first << "\n";
    return 0;
}
----------
  v의 크기를 미리 정의 하지 않고 push_back을 사용할 경우 N이 크면 비효율적일 수 있다.
  v(N)으로 지정한 수 v[i] = {y,x}로 대입해주는 것이 메모리 이득
----------
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{   
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {y, x};
    }
    sort(v.begin(), v.end());
    for(auto p : v) cout << p.second << " " << p.first << "\n";
    return 0;
}
