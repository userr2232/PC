#include <iosrteam>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = 0; i <= b; ++i)
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    FOR(i,0,n-1) FOR(j,0,n-1) {
        cin >> A[i]][j];
        if(i) A[i][j] += A[i-1][j];
        if(j) A[i][j] += A[i][j-1];
        if(i&&j) A[i][j] -= A[i-1][j-1];
    }
    int maxSubRect{-127*n*n}, subRect;
    FOR(i,0,n-1) FOR(j,0,n-1)
        FOR(k,i,n-1) FOR(l,j,n-1) {
            subRect = A[k][l];
            if(i) subRect -= A[i-1][l];
            if(j) subRect -= A[k][j-1];
            if(i&&j) subRect += A[i-1][j-1];
            maxSubRect = max(maxSubRect, subRect);
        }
    cout << maxSubRect << "\n";
    return 0;
}