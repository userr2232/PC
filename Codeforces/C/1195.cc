#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<long long> vi;


int main() {
    int n; cin >> n;
    vector<vi> v(2, vi(n));
    vector<vi> dp(2, vi(n, 0));
    for(auto &row : v) for(auto &e : row) cin >> e;
    dp[0][0] = v[0][0], dp[1][0] = v[1][0];
    for(int j = 1; j < n; ++j) for(int i = 0; i < 2; ++i) {
        dp[i][j] = max(dp[i][j-1], dp[1-i][j-1]+v[i][j]);
        if(j >= 2) dp[i][j] = max(dp[i][j], dp[1-i][j-2]+v[i][j]);
    }
    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
    return 0;
}