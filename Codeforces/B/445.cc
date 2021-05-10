#include <iostream>
#include <vector>

using namespace std;

typedef vector<long long> vi;

class UnionFind {
private: vi p, rank, children;
public:
    UnionFind(long long N) {
        children.assign(N, 1);
        p.assign(N, 0);
        rank.assign(N, 0);
        for(long long i = 0; i < N; ++i) p[i] = i;
    }

    long long findSet(long long i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    void unionSet(long long i, long long j) {
        long long x{findSet(i)}, y{findSet(j)};
        if(rank[x] > rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }

    void solve() {
        long long answer{1};
        for(long long i = 0; i < children.size(); ++i) {
            auto x = findSet(i);
            if(x != i) children[x]++;
        }
        for(long long i = 0; i < children.size(); ++i)
            answer *= (1LL << (children[i] - 1));
        cout << answer << endl;
    }
};

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    auto dsu = UnionFind(n);
    while(m--) {
        cin >> a >> b;
        dsu.unionSet(a-1, b-1);
    }
    dsu.solve();
}