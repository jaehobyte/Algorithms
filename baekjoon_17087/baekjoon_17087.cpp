#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b);

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int map[100010];
	int count = 0;

	for (int i = 0;i < N;i++)
	{	
		int s = 0;
		scanf("%d", &s);

		// 거리의 차를 배열에 삽입하여 거리들의 최대공약수를 구하기 위함
		map[i] = abs(M - s);
		count += 1;
	}

	int result = map[0];

	for (int i = 1; i < count ;i++)
	{
		result = gcd(result, map[i]);
	}

	printf("%d", result);

}

// 최대공약수 재귀함수_유클리드 호제법 
int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}