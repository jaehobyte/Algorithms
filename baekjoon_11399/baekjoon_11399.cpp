#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> list(N);

    for (int i = 0; i < N; i++)
       cin >> list[i];
    sort(list.begin(), list.end());
    
    int sum = 0;
    int ans = 0;

    for (int j = 0; j < N; j++)
    {
        sum += list[j];
        ans += sum;
    }

    cout << ans << endl;
    return 0;
}
