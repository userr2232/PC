#include <iostream>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int x;
    FOR(i,0,n-1) {
        if(i == 0) { x = 0; cout << i << endl; }
        else {
            cout << (i-1 ^ i) << endl;
        }
        int c; cin >> c;
        if(c == 1) { return; }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}