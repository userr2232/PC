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
        LOG = 31-__builtin_clz(N)+1;
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