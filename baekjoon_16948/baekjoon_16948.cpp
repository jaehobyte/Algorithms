#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int dist[200][200];
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = { -1, 1, -2, 2, -1, 1 };

int main()
{
    int size;
    cin >> size;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(dist, -1, sizeof(dist));
    dist[r1][c1] = 0;
    
    queue<pair<int, int>> q;
    q.push(make_pair(r1, c1));

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < size && ny >= 0 && ny < size)
            {
                if (dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
            
        }
    }
    cout << dist[r2][c2] << endl;
}

