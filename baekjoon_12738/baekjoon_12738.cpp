#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> num;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		
		if(num.empty()||num.back()<t)
		{
			num.push_back(t);
		}
		else 
		{
			auto temp = lower_bound(num.begin(), num.end(), t);
			*temp = t;
		}
	}
	cout << num.size() << endl;
}

