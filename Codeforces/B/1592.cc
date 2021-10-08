#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int n, x; cin >> n >> x;
        vector<int> v(n), v2(n);
        for(auto& e: v) cin >> e;
        v2 = v;
        if(n >= 2*x) { cout << "YES\n"; continue; }
        else {
            sort(v.begin(), v.end());
            bool p = false;
            for(int i = n-x; i < x; ++i) if(v[i] != v2[i]) { cout << "NO\n"; p = true; break; }
            if(!p) cout << "YES\n";
        }
    }    
    return 0;
}