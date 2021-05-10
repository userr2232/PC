#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int i = 0; i < n; ++i){
        int x{0};
        if(i == n-2 && v[i] != v[i+1]) break;
        for(int j = i; j < n-1; ++j) {
            if(v[j] != v[j+1]) {
                x++;
                v[j+1] = v[j] ^ v[j+1];
            }
        }
        if(x == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}