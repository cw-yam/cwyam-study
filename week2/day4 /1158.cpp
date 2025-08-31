#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N, K, x;
    cin >> N >> K;
    queue<int> q;
    for(int i = 1; i <= N; i ++)
    {
        q.push(i);
    }
    cout << "<";
    for(int i = 0; i < N; i ++)
    {
        for(int j = 1; j < K; j ++)
        {
            x = q.front();
            q.pop();
            q.push(x);
        }
        
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout << ">";
    return 0;
}
