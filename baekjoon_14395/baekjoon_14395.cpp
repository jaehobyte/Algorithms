#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
using namespace std;

const long long limit = 1000000000LL;

int main()
{
    int a, b;
    cin >> a >> b;

    queue<pair<long long, string>> q;
    string str = "";
    set<long long> check;

    q.push(make_pair(a, ""));

    while (!q.empty())
    {
        long long n = q.front().first;
        str = q.front().second;
        q.pop();

        if (n == b)
        {
            if (str.length() == 0)
            {
                str = '0';
            }
            cout << str << endl;
            return 0;
        }

        if (0 <= n * n && n * n <= limit && check.count(n * n) == 0)
        {
            q.push(make_pair(n * n, str + '*'));
            check.insert(n * n);
        }

        if (0 <= n + n && n + n <= limit && check.count(n + n) == 0)
        {
            q.push(make_pair(n + n, str + '+'));
            check.insert(n + n);
        }

        if (0 <= n - n && n - n <= limit && check.count(n - n) == 0)
        {
            q.push(make_pair(n - n, str + '-'));
            check.insert(n - n);
        }

        if (n != 0 && 0 <= n / n && n / n <= limit && check.count(n / n) == 0)
        {
            q.push(make_pair(n / n, str + '/'));
            check.insert(n / n);
        }
    }
    cout << -1 << endl;
    return 0;
}