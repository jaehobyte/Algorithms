#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int sum;
queue<pair<int, int>> q;
int visited[1501][1501];

void bfs(int x, int y)
{
    q.push(make_pair(x, y));

    visited[x][y] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int a[3] = { x, y, sum - x - y };
        q.pop();

        for (int i = 0;i< 3;i++)
        {
            for (int j = 0; j < 3;j++)
            {
                if (a[i] < a[j])
                {
                    int num1 = a[i] * 2;
                    int num2 = a[j] - a[i];

                    if (visited[num1][num2] == 1)
                        continue;

                    visited[num1][num2] = 1;
                    q.push(make_pair(num1, num2));
                }
            }
        }
    }
    cout << visited[sum / 3][sum / 3] << endl;
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    sum = x + y + z;
    if (sum % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    bfs(x, y);
}
