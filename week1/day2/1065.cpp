#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, count = 0;
    cin >> N;
    for (int t = 1; t <= N; t++) {
        string X = to_string(t);
        if (X.length() <= 2) count++;
        else if ((X[1] - X[0]) == (X[2] - X[1])) count++;
    }
    cout << count;
    return 0;
}
