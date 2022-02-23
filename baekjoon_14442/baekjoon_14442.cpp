#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int N, M, K;
int map[1000][1000];
int visit[1000][1000][11];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void bfs()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ {0, 0}, 0 });
    visit[0][0][0] = 1;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1)
        {
            cout << visit[x][y][z] << endl;
            return;
        }

        for(int i=0; i<4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || N <= nx || ny < 0 || M <= ny) continue;

            if (visit[nx][ny][z] == 0 && map[nx][ny] == 0)
            {
                visit[nx][ny][z] = visit[x][y][z] + 1;
                q.push({ {nx, ny}, z });
            }

            if (visit[nx][ny][z+1] == 0 && z < K && map[nx][ny] == 1)
            {
                visit[nx][ny][z + 1] = visit[x][y][z] + 1;
                q.push({ {nx, ny}, z+1 });
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        string temp; cin >> temp;

        for (int j = 0; j < M; j++)
        {
            map[i][j] = temp[j] - '0';
        }
    }
    bfs();
}
