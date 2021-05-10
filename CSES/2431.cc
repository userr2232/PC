#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

ll digits_before, z;

ll f(ll k) {
    z = -1;
    ll tmp{k};
    digits_before = 1;
    ll p = pow(10.0L,z);
    ll calc = (z+1)*9*p;
    do {
        tmp -= calc;
        digits_before += calc;
        z++;
        p = pow(10.0L,z);
        calc = (z+1)*9*p;
    } while(tmp - calc > 0);
    return p + (k-digits_before) / (z+1);
}

char g(ll k) {
    return to_string(f(k))[(k-digits_before) % (z+1)];
}

void solve() {
    ll k; cin >> k;
    cout << g(k)<< "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; cin >> q;
    while(q--) solve();
    return 0;
}