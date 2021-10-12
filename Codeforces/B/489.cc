#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> boys, girls;
vector<vector<int>> memo;

int dp(int i, int j) {
    if(i == -1 || j == -1) return 0;
    int& ans = memo[i][j];
    if(ans != -1) return ans;
    ans = max(dp(i,j-1), dp(i-1,j));
    if(abs(boys[i]-girls[j]) <= 1) ans = max(ans, dp(i-1,j-1)+1);
    return ans;
}

int main() {
    int n; cin >> n; boys.resize(n);
    for(auto& e : boys) cin >> e;
    int m; cin >> m; girls.resize(m);
    for(auto& e : girls) cin >> e;
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    memo.assign(n, vector<int>(m, -1));
    cout << dp(n-1, m-1) << endl;
    return 0;
}