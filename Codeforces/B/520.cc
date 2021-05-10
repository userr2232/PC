#include <iostream>
#include <queue>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve(int t = 0) {
    int n, m;
    set<ll> visited;
    cin >> n >> m;
    queue<pll> q;
    if(n == m) {
        cout << 0 << endl;
        return;
    }
    q.push({n, 0});
    visited.insert(n);
    while(!q.empty()) {
        auto [x, l] = q.front();
        q.pop();
        if(2*x <= 2*m && visited.count(2*x) == 0) {
            visited.insert(2*x);
            if(2*x == m) {
                cout << l + 1 << endl;
                return;
            }
            else q.push({2*x, l+1});
        }
        if(x-1 && visited.count(x-1) == 0) {
            visited.insert(x-1);
            if(x-1 == m) {
                cout << l + 1 << endl;
                return;
            }
            else q.push({x-1, l+1});
        }
    }
}

int main() {
    solve();
    return 0;
}