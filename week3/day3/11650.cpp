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
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i< N; i ++) cout << v[i].first << " " << v[i].second << "\n";
    return 0;
}
----------
make_pair 생략하고 중괄호{}로 초기화 가능
for(int i = 0; i < N; i ++) 부분 for(autop : v)로 사용가능 (더 간결함)
----------
  
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {   
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    for(auto p : v)
        cout << p.first << " " << p.second << "\n";
    return 0;
} 
