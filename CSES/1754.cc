#include <iostream>
#include <cmath>

using namespace std;

bool is_nn_integer(double d) {
    return d == round(d) && d >= 0;
}

void solve() {
    double a, b; cin >> a >> b;
    double z = (a + b) / 3;
    cout << (is_nn_integer((z + a - b)/2) && is_nn_integer((z + b - a)/2) ? "YES" : "NO" ) << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}