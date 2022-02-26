#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, M;
char map[50][50];
int visited[50][50];
int w[50][50];

int dx[] = { 1, -1, 0, 0 };
int dy[] = {0, 0, 1, -1};

int bfs()
{
    queue<pair<int, int>> q;
    int sx, sy, ex, ey;

    memset(w, -1, sizeof(w));
    for (int i = 0;i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == '*')
            {
                q.push(make_pair(i, j));
                w[i][j] = 0;
            }       
            else if (map[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (map[i][j] == 'D')
            {
                ex = i;
                ey = j;
            }
        }
    }

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX >= 0 && N > nextX && nextY >= 0 && M > nextY)
            {
                if (visited[nextX][nextY] == 0)
                {
                    if (w[nextX][nextY] != -1) continue;
                    if (map[nextX][nextY] == 'X') continue;
                    if (map[nextX][nextY] == 'D') continue;
                    w[nextX][nextY] = w[x][y] + 1;
                    q.push(make_pair(nextX, nextY));
                }
            }
        }
    }

    memset(visited, -1, sizeof(visited));
    q.push(make_pair(sx, sy));
    visited[sx][sy] = 0;

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX >= 0 && N > nextX && nextY >= 0 && M > nextY)
            {
                if (map[nextX][nextY] == 'X') continue;
                if (visited[nextX][nextY] != -1) continue;
                if (w[nextX][nextY] != -1 && visited[x][y] + 1 >= w[nextX][nextY]) continue;
              
                visited[nextX][nextY] = visited[x][y] + 1;
                q.push(make_pair(nextX, nextY));            
            }
        }
    }

    if (visited[ex][ey] == -1) {
        cout << "KAKTUS\n";
    }
    else {
        cout << visited[ex][ey] << '\n';
    }
    return 0;
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string temp; cin >> temp;
        for (int j = 0;j < M; j++)
        {
            map[i][j] = temp[j];
        }
    }
    bfs();
}

