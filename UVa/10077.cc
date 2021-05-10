#include <iostream>
#include <vector>

#define pb(a) push_back(a)

using namespace std;

typedef vector<int> vi;

int n, m;

void fractions(int numerator, int denominator, vi& v) {
    if(numerator == 1) return;
    v.pb(numerator / denominator);
    fractions(denominator, numerator % denominator, v);
}

void solve() {
    vi v;
    if(m < n) {
        v.pb(0);
        fractions(n, m, v);
    }
    else fractions(m, n, v);
    int sz = v.size();
    v[sz-1]--;
    for(int i = 0; i < sz; ++i) {
        while(v[i]--) {
            if(i%2) cout << "L";
            else cout << "R";
        }
    }
    cout << endl;
}


int main() {
    while(cin >> m >> n, n != 1 || m != 1) {
        solve();
    }
    return 0;
}