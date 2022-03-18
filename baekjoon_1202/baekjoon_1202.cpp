#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

struct jewel {
    int m, v;
};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    vector<jewel> J(N);

    for (int i = 0;i < N;i++)
    {
        scanf("%d %d", &J[i].m, &J[i].v);
    }

    sort(J.begin(), J.end(), [](jewel u, jewel v) {
        return u.v > v.v;
     });

    multiset<int> B;

    for (int i = 0;i < M;i++)
    {
        int t;
        scanf("%d", &t);
        B.insert(t);
    }

    long long ans = 0;
    for (int i = 0;i < N;i++) {
        auto it = B.lower_bound(J[i].m);
        if (it != B.end()) {
            ans += J[i].v;
            B.erase(it);
        }
    }
    printf("%lld\n", ans);
    return 0;

}


