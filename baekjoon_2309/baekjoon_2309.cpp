#include <iostream>
#include <algorithm>
using namespace std;

int a[9];

int main()
{
	int sum = 0;
	for (int i = 0;i < 9;i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + 9);

	for (int i = 0;i < 9;i++)
	{
		for (int j = i + 1; j < 9;j++)
		{
			if (sum - a[i] - a[j] == 100)
			{
				for (int k = 0;k < 9;k++)
				{
					if (k == i || k == j) continue;
					cout << a[k] << endl;
				}
				return 0;
			}
		}
	}
}

