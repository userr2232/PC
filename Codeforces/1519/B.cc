#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

vector<vector<complex<double>>> memo;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    memo = vector<vector<complex<double>>>(n, vector<complex<double>>(m, {0, 0}));
    if(i) dp[i][j] += im(dp[i-1][j]) + {0, j};
    if(j) dp[i][j] += dp[i][j-1] + {i, 0};
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}