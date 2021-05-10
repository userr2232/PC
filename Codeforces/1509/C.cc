#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef vector<long long> vll;

int n;
vll v;
bitset<2000> zeros, available;

map<pair<long long, string>, long long> mm;

long long dp(long long rmin, long long rmax, long long sum, bitset<2000>& available) {
    long long curmin, curmax, cursum{(long long)3e12};
    if(available == zeros) return sum;
    string s = available.to_string();
    if(mm.count({sum, s})) return mm[{sum, s}];
    for(int i = 0; i < n; ++i) {
        if(available[i]) {
            available[i] = 0;
            curmin = min(rmin, v[i]);
            curmax = max(rmax, v[i]);
            cursum = min(cursum, dp(curmin, curmax, sum + curmax-curmin, available));
            available[i] = 1;
        }
    }
    mm[{sum, s}] = cursum;
    return cursum;
}

int main() {
    cin >> n;
    zeros = bitset<2000>();
    available = bitset<2000>(string(n, '1'));
    v.assign(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << dp(3e12, 0, 0, available) << endl;
}