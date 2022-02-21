#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int N, M;
int visited[1000][1000][2];
int map[1000][1000];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void bfs()
{
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(0, 0, 0));

    visited[0][0][0] = 1;

    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 > nx || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny][z] == 0 && map[nx][ny] == 0)
            {
                visited[nx][ny][z] = visited[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z));
            }

            if (z==0 && map[nx][ny] == 1)
            {
                visited[nx][ny][z + 1] = visited[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z+1));
            }
        }
    }
}


int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string temp; cin >> temp;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = temp[j] - '0';
        }
    }
    bfs();
    if (visited[N - 1][M - 1][0] != 0 && visited[N - 1][M - 1][1] != 0)
    {
        cout << min(visited[N - 1][M - 1][0], visited[N - 1][M - 1][1]) << endl;
    }
    else if(visited[N-1][M-1][0] != 0)
    {
        cout << visited[N - 1][M - 1][0] << endl;
    }
    else if (visited[N - 1][M - 1][1] != 0)
    {
        cout << visited[N - 1][M - 1][1] << endl;
    }
    else
    {
        cout << -1 << endl;
    }   
}
