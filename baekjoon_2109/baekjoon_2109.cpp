#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Lecture {
	int p, d;
};

bool cmp(const Lecture& u, const Lecture& v) {
	return u.d > v.d;
}

int main() {
	int n;
	cin >> n;
	vector<Lecture> a(n);

	//강의 기간, 비용 입력
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].p >> a[i].d;
	}
	
	sort(a.begin(), a.end(), cmp);
	int k = 0;
	priority_queue<int> q;
	int ans = 0;
	for (int i = 10000; i >= 1; i--) {
		while (k < n && a[k].d == i) {
			q.push(a[k].p);
			k += 1;
		}
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}