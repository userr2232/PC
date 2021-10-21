#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

class SparseTable {
private:
    vi A;
    vector<vector<int>> SpT;
    int LOG, N;
public:
    SparseTable(vi& initialA) {
        A = initialA;
        N = A.size();
        LOG = 31-__builtin_clz(N)+1; // +1 in case N is a power of 2 and we need to have k == LOG in RMQ
        SpT.resize(N, vector<int>(LOG, 0));
        for(int i = 0; i < N; ++i) SpT[i][0] = A[i];
        for(int j = 1; j < LOG; ++j) for(int i = 0; i + (1<<j) - 1 < N; ++i) {
            SpT[i][j] = min(SpT[i][j-1], SpT[i+(1<<(j-1))][j-1]);
        }
    }

    int RMQ(int L, int R) {
        int len = R-L+1;
        int k = 31 - __builtin_clz(len);
        return min(SpT[L][k], SpT[R-(1<<k)+1][k]);
    }
};

int main() {
    int n; cin >> n;
    vi A(n); for(auto& e : A) cin >> e;
    auto spt = SparseTable(A);
    cout << spt.RMQ(0, 7) << endl;
}