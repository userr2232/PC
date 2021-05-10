#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_integer(double a) {
    return round(a) == a;
}

bool is_perfectsq(int a, int b) {
    return is_integer(sqrt(a * b));
}

void solve() {
    int n, tmp; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(!is_perfectsq(v[i], v[j])) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while(t--)
    solve();
    return 0;
}