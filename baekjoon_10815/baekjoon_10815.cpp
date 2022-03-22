#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[500000];
int n;

int binary_search(int num)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == num)
        {
            return 1;
        }
        else if (a[mid] > num) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);

    int m;
    scanf("%d", &m);

    while(m--)
    {
        int t;
        scanf("%d", &t);
        printf("%d ", binary_search(t));
    }
}
