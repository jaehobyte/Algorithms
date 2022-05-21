#include <string>
#include <iostream>

using namespace std;

int dx[] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

char map[5][5];
/*recursive BFS*/

bool inRange(int x, int y)
{
    if (x < 0 || x >= 5 || y < 0 || y >= 5) return false;
    return true;
}

bool hasWord(int x, int y, const string& word)
{
    if (!inRange(x, y)) return false;
    if (map[x][y] != word[0]) return false;
    if (word.size() == 1) return true;

    for (int d = 0;d < 8;d++)
    {
        int nx = dx[d] + x;
        int ny = dy[d] + y;
        if (hasWord(nx, ny, word.substr(1)))
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> map[i];
        }

        int n;
        cin >> n;
        bool check = false;
        while (n--)
        {
            string word;
            cin >> word;

            for (int i = 0;i < 5;i++) {
                for (int j = 0;j < 5;j++)
                {
                    if (check = hasWord(i, j, word)) {
                        break;
                    }
                    if (check) break;
                }
            }
            if (check) cout << word << " YES" << endl;
            else cout << word << " NO" << endl;
        }
    }
    return 0;
}
