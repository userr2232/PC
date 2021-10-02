#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

typedef vector<int> vi;

int main() {
    int n; cin >> n;
    vi prices(n);
    for(auto& e: prices) cin >> e;
    sort(prices.begin(), prices.end());
    int q; cin >> q;
    FOR(i,1,q) {
        int m; cin >> m;
        int pos = upper_bound(prices.begin(), prices.end(), m) - prices.begin();
        cout << pos << endl;
    }
    return 0;
}