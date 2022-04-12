#include <iostream>

using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;
    cout << (6916 * e + 4845 * s + 4200 * m - 1) % (15 * 28 * 19) + 1 << '\n';
    return 0;
}