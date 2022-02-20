#include <iostream>
#include <queue>
using namespace std;

int N, M;
int a[8][8];
int b[8][8];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int bfs()
{
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			b[i][j] = a[i][j];
			if (b[i][j] == 2)
			{
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty())
	{
		int x, y;
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M) {
				if (b[nextX][nextY] == 0) {
					b[nextX][nextY] = 2;
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (b[i][j] == 0)
				cnt += 1;
		}
	}
	return cnt;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N;i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}

	int x1, x2, x3;
	int y1, y2, y3;
	int ans = 0;

	for (int x1 = 0; x1 < N; x1++) {
		for (int y1 = 0; y1 < M; y1++) {
			if (a[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < N; x2++) {
				for (int y2 = 0; y2 < M; y2++) {
					if (a[x2][y2] != 0) continue;
					for (int x3 = 0; x3 < N; x3++) {
						for (int y3 = 0; y3 < M; y3++) {
							if (a[x3][y3] != 0) continue;
							if (x1 == x2 && y1 == y2) continue;
							if (x1 == x3 && y1 == y3) continue;
							if (x2 == x3 && y2 == y3) continue;
							a[x1][y1] = 1;
							a[x2][y2] = 1;
							a[x3][y3] = 1;
							int cur = bfs();
							if (ans < cur) ans = cur;
							a[x1][y1] = 0;
							a[x2][y2] = 0;
							a[x3][y3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

