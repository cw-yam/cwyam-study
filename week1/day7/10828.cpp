#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x;
    cin >> N;
    string s;
    stack<int> st;

    while(N--) {
        cin >> s;
        if(s == "push") {
            cin >> x;
            st.push(x);
        }
        else if(s == "pop") {
            if(st.empty()) cout << -1 << "\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(s == "size") {
            cout << st.size() << "\n";
        }
        else if(s == "empty") {
            cout << (st.empty() ? 1 : 0) << "\n";
        }
        else if(s == "top") {
            if(st.empty()) cout << -1 << "\n";
            else cout << st.top() << "\n";
        }
    }

    return 0;
}
