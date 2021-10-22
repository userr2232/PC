#include <iostream>
#include <vector>
#define SIGN(x) ((x > 0) - (x < 0))
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for(auto& e: v) cin >> e;
    int l = 0, prev_sign{0}, ans{2};
    for(int i = 1; i < n; ++i) {
        int diff = v[i]-v[i-1];
        int sign = SIGN(diff);
        if(sign == 0) {}
        else {
            if(sign == prev_sign) {
                int j = i;
                for(; j >= l; --j) {
                    if(abs(v[j]-v[i]) == 2) break;
                }
                l = j+1;
            }
            prev_sign = sign;
        }
        ans = max(ans, i-l+1);
    }
    // cerr << l << endl;
    cout << ans << endl;
}