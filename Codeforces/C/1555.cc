#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int m; cin >> m;
        vector<vector<int>> M(2, vector<int>(m));
        FOR(i,0,1) FOR(j,0,m-1) {
            cin >> M[i][j];
        }
        int ans = 2e9;
        int sum1{0}, sum2{0};
        FOR(j,0,m-1) sum1 += M[0][j];
        FOR(j,0,m-1) {
            sum1 -= M[0][j];
            ans = min(ans, max(sum1, sum2));
            sum2 += M[1][j];
        }
        cout << ans << endl;
    }
}