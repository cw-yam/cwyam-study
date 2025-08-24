#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int N, x;
    cin >> N;
    queue<int> q;
    string s;
    while(N--)
    {
        cin >> s;
        if(s == "push") 
        {
            cin >> x; 
            q.push(x);
        }
        else if(s == "pop") 
        {
            if(q.empty()) cout << "-1\n"; 
            else {cout << q.front() <<"\n"; q.pop();}  
        }
        else if(s == "size") cout << q.size() << "\n";
        else if(s == "empty") cout << (q.empty() ? "1" : "0") << "\n";
        else if(s == "front")
        {
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else if(s == "back")
        {
            if(q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }
    return 0;
}
