#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;

classSparseTable {
private:
    vi A, L2, P2;,
    vector<vi> SpT;
public:
    SparseTable(vi& initialA) {
        A = initialA;
        int n = A.size();
        int L2_n = log2(n)+1;
        L2.assign((1<<L2_n)+1,0);
        P2.assign(L2_n+1,0);
        FOR(i,0,L2_n) L2[(1<<i)] = i, P2[i] = (1<<i);
        FOR(i,2,P2[L2_n]) if(L2[i] == 0) L2[i] = L2[i-1];
        SpT = vector<vi>(L2_n, vi(n));
        FOR(i,0,n-1) SpT[0][i] = i;
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