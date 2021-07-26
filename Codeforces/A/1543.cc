#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void solve() {
    long long a, b; cin >> a >> b;
    if(a < b) swap(a, b);
    long long c = a - b;
    if(a == b) { cout << "0 0" << endl; return; }
    if(a%c == 0 && b%c == 0) { cout << c << " " << 0 << endl; return; }
    else {
        long long d_d = b / c;
        long long d_u = d_d + 1;
        cout << c << " " << min(abs(d_d*c-b), abs(d_u*c-b)) << endl;
        return;
    }
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}