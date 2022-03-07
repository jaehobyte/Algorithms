#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> a(N);

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	int ans = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		ans += M / a[i];
		M %= a[i];
	}

	cout << ans << endl;
	return 0;

}
