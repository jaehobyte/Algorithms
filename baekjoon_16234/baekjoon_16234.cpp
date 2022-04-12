#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, l, r;
int nation[50][50];
bool visited[50][50];

int sum;
int cnt;
bool flag;
int ans;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

vector<pair<int, int>> v;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;
    v.push_back(make_pair(x, y));
    cnt++;
    sum += nation[x][y];

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visited[nx][ny] == true) continue;

            if (abs(nation[x][y] - nation[nx][ny]) >= l && abs(nation[x][y] - nation[nx][ny]) <= r)
            {
                sum += nation[nx][ny];
                cnt += 1;
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                v.push_back(make_pair(nx, ny)); 
            }
        }   
    }

    if (v.size() > 1)
    {
        int avg = sum / cnt;

        for (int i = 0; i < v.size(); i++) {
            int x = v[i].first;
            int y = v[i].second;
            nation[x][y] = avg;
        }

        flag = true;
    }
    v.clear();
    sum = 0;
    cnt = 0;
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cin >> nation[i][j];
        }
    }

    ans = 0; sum = 0; cnt = 0;

    while (true)
    {
        memset(visited, false, sizeof(visited));
        flag = false;
        for(int i = 0; i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (!visited[i][j])
                {
                    bfs(i, j);
                }
            }
        }

        if (flag) ans++;
        else break;
    }

    cout << ans << endl;
}

