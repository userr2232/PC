#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

class SparseTable {
private:
    vector<vi> SpT;
    int N, LOG;
public:
    SparseTable(const vi& A) {
        N = A.size();
        LOG = 31 - __builtin_clz(N)+1;
        SpT.resize(N, vi(LOG));
        for(int i = 0; i < N; ++i) SpT[i][0] = A[i];
        for(int j = 1; j < LOG; ++j) for(int i = 0; i + (1<<j) - 1 < N; ++i) {
            SpT[i][j] = min(SpT[i][j-1], SpT[i+(1<<(j-1))][j-1]);
        }
    }

    int RMQ(int L, int R) {
        int k = 31 - __builtin_clz(R-L+1);
        return min(SpT[L][k], SpT[R-(1<<k)+1][k]);
    }
};

int main() {
    int n, q; cin >> n >> q;
    vi v(n); for(auto& e : v) cin >> e;
    SparseTable table(v);
    for(int i = 0; i < q; ++i) {
        int L, R; cin >> L >> R;
        cout << table.RMQ(L-1, R-1) << endl;
    }
}