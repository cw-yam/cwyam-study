#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for(int i = 0; i < N; i++) cin >> board[i];

    int min_change = 64;

    for(int i = 0; i <= N-8; i++)
    {
        for(int j = 0; j <= M-8; j++)
        {
            int cnt1 = 0, cnt2 = 0;

            for(int x = 0; x < 8; x++)
            {
                for(int y = 0; y < 8; y++)
                {
                    char current = board[i+x][j+y];

                    if((x+y)%2 == 0)
                    {
                        if(current != 'W') cnt1++;
                        if(current != 'B') cnt2++;
                    }
                    else 
                    {
                        if(current != 'B') cnt1++;
                        if(current != 'W') cnt2++;
                    }
                }
            }
            min_change = min(min_change, min(cnt1, cnt2));
        }
    }

    cout << min_change << "\n";
    return 0;
}
