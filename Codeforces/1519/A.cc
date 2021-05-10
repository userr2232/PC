#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int,int> ii;

void solve() {
    int r, b, d; cin >> r >> b >> d;
    if(((max(r, b) % min(r, b)) ? 1 : 0) + max(r, b) / min(r, b) - 1 > d) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}