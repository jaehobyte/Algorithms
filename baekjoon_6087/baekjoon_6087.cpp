#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main()
{
	int W, H;
	cin >> W >> H;

	int sx, sy, ex, ey;
	sx = sy = ex = ey = -1;
	vector<string> map(H);  

	for (int i = 0; i < H; i++)
	{
		cin >> map[i];
		for (int j = 0;j < W; j++)
		{
			if (map[i][j] == 'C')
			{
				if (sx == -1)
				{
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
			}
		}
	}

	vector<vector<int>> visited(H, vector<int>(W, -1));
	queue<pair<int, int>> q;
	visited[sx][sy] = 0;
	q.push(make_pair(sx, sy));

	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front(); q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			while (0 <= nx && nx < H && 0 <= ny && ny < W)
			{
				if (map[nx][ny] == '*') break;
				if (visited[nx][ny] == -1)
				{
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}
	cout << visited[ex][ey] - 1 << endl;
}
