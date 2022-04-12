#include <iostream>
#include <queue>
using namespace std;

struct bead 
{
    int rx, ry;
    int bx, by;
    int d;
};

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

char map[10][10];
bool visited[10][10][10][10] = { false }; // 빨간 구슬, 파란구슬 이동을 기록하는 배열
int n, m;
queue<bead> q;

void bfs()
{
    while (!q.empty())
    {
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int d = q.front().d;
        q.pop();

        if (d >= 10) break;
     
        for (int i = 0;i < 4;i++)
        {
            int r_nx = rx;
            int r_ny = ry;
            int b_nx = bx;
            int b_ny = by;  
            int nd = d + 1;
            int rc = 0;
            int bc = 0;

            //빨간 구슬 굴리기
            while (map[r_nx + dx[i]][r_ny + dy[i]] != '#' && map[r_nx][r_ny] != 'O')
            {
                r_nx += dx[i];
                r_ny += dy[i];
                rc += 1;
            }
            
            // 파란 구슬 굴리기
            while (map[b_nx + dx[i]][b_ny + dy[i]] != '#' && map[b_nx][b_ny] != 'O')
            {
                b_nx += dx[i];
                b_ny += dy[i];
                bc += 1;
            }

            if (map[b_nx][b_ny] == 'O') continue;
            if (map[r_nx][r_ny] == 'O')
            {
                cout << nd << endl;
                return;
            }

            // 구슬이 겹친 경우, 더 많이 count된 구슬을 한칸 뒤로 미루면 됨
            if (r_nx == b_nx && r_ny == b_ny)
            {
                if (map[r_nx][r_ny] == 'O') continue;
                if (rc > bc)
                {
                    r_nx -= dx[i];
                    r_ny -= dy[i];
                }
                else
                {
                    b_nx -= dx[i];
                    b_ny -= dy[i];
                }
            }

            if (visited[r_nx][r_ny][b_nx][b_ny]) continue;
            visited[r_nx][r_ny][b_nx][b_ny] = true;
            q.push({ r_nx, r_ny, b_nx, b_ny,nd });
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int rx, ry, bx, by = 0;

    for (int i = 0;i < n;i++)
    {
        string s;
        cin >> s;
        for (int j = 0;j < m;j++)
        {
            map[i][j] = s[j];
            if (s[j] == 'R')
            {
                rx = i;
                ry = j;
            }
            else if(s[j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }
    q.push({ rx,ry,bx,by,0 });
    visited[rx][ry][bx][by] = true;
    bfs();
}

