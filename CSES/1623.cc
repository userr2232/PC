#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(ll i = a; i <= b; ++i)
using namespace std;
typedef long long ll;
ll mask, total;
vector<ll> s;
int n;
ll sum() {
    ll ans{0};
    FOR(i,0,n-1) if(mask&(1LL<<(i-1)))  ans += s[i];
    return ans;
}
int main() {
    cin >> n; s.assign(n+1, 0);
    mask = (1 << n) - 1;
    FOR(i,1,n) cin >> s[i], total += s[i];
    ll ans = 1e12;
    do {
        ll sm{sum()};
        ans = min(ans, abs(total-sm-sm));
    } while(mask--);
    cout << ans << endl;
    return 0;
}