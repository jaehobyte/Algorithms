#include <iostream>
#include <set>

using namespace std;

/* 정렬된 이진트리를 확인하기 위한 문제
c++에서는 set, map을 사용하면 된다. 정렬된 상태가 필요없다면 unordered_set을 사용하면 됨 
rbegin을 사용하는 이유는 역순으로 출력 전위순회, 후위순회에 관련됨 */

int main() {
	int n;
	cin >> n;
	set<string> data;

	while (n--)
	{
		string name, what;
		cin >> name >> what;

		if (what == "enter") {
			data.insert(name);
		}
		else {
			data.erase(data.find(name));
		}
	}

	for (auto i = data.rbegin(); i != data.rend(); i++)
	{
		cout << *i << endl;
	}
	return 0;
}