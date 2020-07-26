#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int inclusion_exclusion(int n, const vector<int>& v) {
    long long ans = 0;
    for(int bitmask = 0; bitmask < (1 << v.size()); ++bitmask) {
        int sign = 1;
        long long lcm = 1;
        for(int i = 0; i < v.size(); ++i) {
            if(bitmask & (1 << i)) {
                sign *= -1;
                long long g = gcd(lcm, v[i]);
                if(n / lcm < v[i] / g) {
                    lcm = n + 1;
                    break;
                }
                lcm *= v[i] / g;
            }
        }
        ans += sign * n / lcm;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, a, d;
        cin >> n >> m >> a >> d;
        vector<int> v = {a, a + d, a + 2*d, a + 3*d, a + 4*d};
        cout << inclusion_exclusion(m, v) - inclusion_exclusion(n - 1, v) << endl;
    }
    return 0;
}