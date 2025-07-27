#include <iostream>
using namespace std;

int main()
{
    int N, M, count = 0;
    cin >> N;
    int arr1[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr1[i];
    }
    cin >> M;
    int arr2[M];
    for(int i = 0; i < M; i++)
    {
        cin >> arr2[i];
    }
    for(int i = 0; i < M; i ++)
    {
        for(int j = 0; j < N; j ++)
        {
            if(arr2[i] == arr1[j])
            {
                count = 1;
            }
        }
        cout << count << "\n";
        count = 0;
    }
    return 0;
} 
-----------------------------------------
    
❗ 시간 초과로 인한 실패  
    
-----------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N;
    vector<int> arr(N);
    
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    cin >> M;
    while (M--)
    {
        int x;
        cin >> x;
        if(binary_search(arr.begin(), arr.end(), x)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
  
