#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
const int INF = 250*1e6+1;
vector<vector<int>> v, dp;
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    v.assign(n, vector<int>(m));
    dp.assign(n, vector<int>(m, INF));
    FOR(i,0,n-1) FOR(j,0,m-1) cin >> v[i][j], dp[i][j] = INF;
    dp[0][0] = 0;
    FOR(i,0,n-1) FOR(j,0,m-1) {
        if(i+1 < n) dp[i+1][j] = min(v[i][j]+dp[i][j], dp[i+1][j]);
        if(j+1 < m) dp[i][j+1] = min(v[i][j]+dp[i][j], dp[i][j+1]);
    }
    cout << dp[n-1][m-1] + v[n-1][m-1] << endl;
}