#include <cstdio>
using namespace std;

int a[50][50];
int b[50][50];

void flip(int x, int y) {
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            a[i][j] = 1 - a[i][j];
        }
    }
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
        
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &b[i][j]);
        }
    }

    int ans = 0;

    for (int i = 0;i < N - 2;i++)
    {
        for (int j = 0;j < M - 2;j++)
        {
            if (a[i][j] != b[i][j])
            {
                flip(i+1, j+1);
                ans += 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] != b[i][j]) {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
