#include <iostream>
#include <algorithm>

#define rank _rank

using namespace std;
int parent[1000001];
int rank[1000001];

int Find(int x) {
    if (x == parent[x]) {
        return x;
    }
    else {
        /* 
        return Find(parent[x]) 를 안쓰는 이유
        유니온 파인드의 시간복잡도는 최대 n이 걸릴 수 있으므로 경로 압축을 해주는 것
        트리가 어떻게 구성되어있는지는 중요하지 않으니
        */      
        return parent[x] = Find(parent[x]);
    }
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;

    /*
    유니온을 구현할 때 rank를 사용할 수 있음, 트리 높이와도 같은데
    경로 압축을 통한다면 트리의 높이와 다른 의미를 가지게 할 수 있음
    */
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) {
        rank[x] = rank[y] + 1;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    while (m--) {
        int w, x, y;
        cin >> w >> x >> y;
        if (w == 0) {
            Union(x, y);
        }
        else {
            x = Find(x);
            y = Find(y);
            if (x == y) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }
}