#include <iostream>
using namespace std;

int map[1000001];

int go(int n) {

    if (n == 1) {
        return 0;
    }

    if (map[n] > 0) {
        return map[n];
    }

    map[n] = go(n - 1) + 1;

    if (n % 2 == 0) {
        int t = go(n / 2) + 1;
        if (map[n] > t) {
            map[n] = t;
        }
    }

    if (n % 3 == 0) {
        int t = go(n / 3) + 1;
        if (map[n] > t) {
            map[n] = t;
        }
    }
    return map[n];
}
int main() {
    int n;
    cin >> n;
    cout << go(n) << '\n';
    return 0;
}