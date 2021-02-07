#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

map<pair<int, int>, int> memo;
vector<pair<int,int>> ts;

int DP(int i, int l) {
    if(i == ts.size() - 1) return 1;
    if(memo.count({i, l})) return memo[{i, l}];
    auto [x, h] = ts[i];
    if(l == -1 || l < x - h) {
        memo[{i, l}] = DP(i + 1, x) + 1;
        return memo[{i, l}];
    }
    auto [xr, hr] = ts[i + 1];
    if(x + h >= xr)
        memo[{i, l}] = DP(i + 1, x);
    else
        memo[{i, l}] = DP(i + 1, x + h) + 1;
    return memo[{i, l}];
}

int main() {
    int n;
    cin >> n;
    int x, h;
    ts = vector<pair<int,int>>(n);
    for(int i = 0; i < n; ++i) {
        cin >> x >> h;
        ts[i] = {x, h};
    }
    cout << DP(0, -1) << endl;
}