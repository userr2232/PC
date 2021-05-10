#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int first = 0;
    while(k--) {
        while(first < n-1 && v[first] == 0) first++;
        if(first >= n-1) break;
        v[first]--;
        v[n-1]++;
        if(v[first] == 0) first++;
    }
    for(int i = 0; i < n; ++i) cout << v[i] << " ";
    cout << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}