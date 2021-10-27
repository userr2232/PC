#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;

int m, n;

bool can_generate(const vector<vi>& A, const vector<vi>& B) {
    vector<vi> B_prime(m, vi(n, 0));
    FOR(i,0,m-1) FOR(j,0,n-1) {
        if(A[i][j]) {
            FOR(k,0,n-1) B_prime[i][k] = 1;
            FOR(l,0,m-1) B_prime[l][j] = 1;
        }
    }
    FOR(i,0,m-1) FOR(j,0,n-1) {
        if(B_prime[i][j] != B[i][j]) return false;
    }
    return true;
}

int main() {
    cin >> m >> n;
    vector<vi> B(m, vi(n, 0)), A(m, vi(n, 1));
    FOR(i,0,m-1) FOR(j,0,n-1) {
        cin >> B[i][j];
        if(B[i][j] == 0) {
            FOR(k,0,n-1) A[i][k] = 0;
            FOR(l,0,m-1) A[l][j] = 0;
        }
    }
    if(can_generate(A, B)) {
        cout << "YES\n";
        FOR(i,0,m-1) {
            FOR(j,0,n-1)
                cout << A[i][j] << (j == n-1 ? "" : " ");
            cout << endl;
        }
    }
    else {
        cout << "NO\n";
    }
}