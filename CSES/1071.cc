#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long r, c; cin >> r >> c;
    long long root = max(r, c);
    if(root%2) cout << ( c == root ? root*root-r+1 : (root-1)*(root-1)+c ) << endl;
    else cout << ( r == root ? root*root-c+1 : (root-1)*(root-1)+r ) << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}