#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

void solve() {
    long long n; cin >> n;
    long long sum{0};
    FOR(i,0,n-1) {
        long long tmp; cin >> tmp;
        sum += tmp;
    }
    long long rem = sum % n;
    cout << rem * (n-rem) << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}