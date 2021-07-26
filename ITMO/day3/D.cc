#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
const int MAX_N = 1e3+10, MAX_W = 1e3+10;
int n, w, W[MAX_N], C[MAX_N], dp[MAX_N][MAX_W];

int knapsack(int id, int remW) {
    int &ans = dp[id][remW];
    if(id == n || remW == 0) return ans = 0;
    if(ans != - 1) return ans;
    if(W[id] > remW) return ans = knapsack(id+1, remW);
    return ans = max(knapsack(id+1, remW), knapsack(id+1, remW-W[id]) + C[id]);
}

int main() {
    cin >> n >> w;
    memset(dp, -1, sizeof dp);
    FOR(i,0,n-1) cin >> W[i];
    FOR(i,0,n-1) cin >> C[i];
    auto ans = knapsack(0,w);
    set<int> s;
    for(int i = 0; i < n; ++i) {
        if(ans == dp[i+1][w]) continue;
        s.insert(i+1);
        ans -= C[i], w -= W[i];
    }
    cout << s.size() << "\n";
    for(auto e : s) cout << e << " ";
}