#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int W, H;
char map[100][100];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int sx, sy, ex, ey;
int mirror;
queue<pair<int, int>> q;

void bfs()
{
    vector<vector<int>> visited(H, vector<int>(W, -1));
    visited[sx][sy] = 0;

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front(); q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            while (0 <= nx && nx < W && 0 <= ny && ny < H) {
                if (map[nx][ny] == '*') break;
                if (visited[nx][ny] == -1) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                nx += dx[k];
                ny += dy[k];
            }
        } 
    }
    cout << visited[ex][ey] << endl;
}

int main()
{
    cin >> W >> H;

    sx = sy = ex = ey = -1;

    for (int i = 0; i < H; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < W; j++)
        {
            map[i][j] = temp[j];
            if (map[i][j] == 'C')
            {
                if (sx == -1)
                {
                    sx = i;
                    sy = j;
                }
                else
                {
                    ex = i;
                    ex = j;
                }
            }
        }
    }

    q.push(make_pair(sx, sy));
    bfs();
}

