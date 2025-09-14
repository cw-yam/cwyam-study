#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 1, c = 1;
    cin >> a >> b >> c;    
    while(a != 0 and b != 0 and c != 0)
    {
        if(a*a == b*b + c*c) cout << "right\n";
        else if(b*b == a*a + c*c) cout << "right\n";
        else if(c*c == a*a + b*b) cout << "right\n";
        else cout << "wrong\n";
        cin >> a >> b >> c;
    }
    return 0;
}

--------
  #include <algorithm> 을 사용한 새로운 풀이 

--------
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int l[3];
    while(true) {
        cin >> l[0] >> l[1] >> l[2];
        if(l[0] == 0 && l[1] == 0 && l[2] == 0) break;

        sort(l, l+3);
        if(l[2]*l[2] == l[0]*l[0] + l[1]*l[1])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
    return 0;
}
