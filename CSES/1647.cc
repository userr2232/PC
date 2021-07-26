#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;

class SparseTable {
private:
    vi A, L2, P2;
    vector<vi> SpT;
public:
    SparseTable() {}

    SparseTable(vi& initialA) {
        A = initialA;
        int n = A.size();
        int L2_n = (int)log2(n)+1;
        P2.assign(L2_n+1,0);
        L2.assign((1<<L2_n)+1,0);
        FOR(i,0,L2_n) P2[i] = (1<<i), L2[(1<<i)] = i;
        FOR(i,2,P2[L2_n]-1) if(L2[i] == 0) L2[i] = L2[i-1];
        
        SpT = vector<vi>(L2[n]+1, vi(n));
        FOR(j,0,n-1) SpT[0][j] = j;

        for(int i = 1; P2[i] <= n; ++i)
            for(int j = 0; j+P2[i]-1 < n; ++j) {
                int x = SpT[i-1][j];
                int y = SpT[i-1][j+P2[i-1]];
                SpT[i][j] = A[x] <= A[y] ? x : y;
            }
    }

    int RMQ(int i, int j) {
        int k = L2[j-i+1];
        int x = SpT[k][i];
        int y = SpT[k][j-P2[k]+1];
        return A[x] <= A[y] ? x : y;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    vi v(n);
    for(auto& e : v) cin >> e;
    SparseTable SpT(v);
    int a, b;
    while(q--) cin >> a >> b, cout << v[SpT.RMQ(a-1, b-1)] << endl;
    return 0;
}