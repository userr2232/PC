#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> boys(n); for(auto& e : boys) cin >> e;
    int m; cin >> m;
    vector<int> girls(m); for(auto& e : girls) cin >> e;
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        dp[i][j] = max(dp[i][j], dp[i-1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j-1]);
        if(abs(boys[i-1]-girls[j-1]) <= 1)
            dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
    }
    cout << dp[n][m] << endl;
}