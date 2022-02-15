#include <iostream>
#include <queue>
using namespace std;
#define next __next

int dist[101]; //check visited
int next[101]; //next position

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= 100;i++)
    {
        dist[i] = 0;
        next[i] = i;
    }

    while (n--)
    {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }

    queue<int> q;
    q.push(1);

    int x, y;

    while (!q.empty())
    {
        x = q.front(); q.pop();

        for (int i = 1; i <= 6; i++)
        {
            y = x + i;
            if (y>100)
                continue;
            y = next[y];

            if (dist[y] == 0)
            {
                dist[y] = dist[x] + 1;
                q.push(next[y]);
            }
        }
    }
    cout << dist[100] << endl;
}


