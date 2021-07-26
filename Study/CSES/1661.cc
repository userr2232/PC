#include <iostream>
#include <map>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, x, tmp; cin >> n >> x;
    long long sum{0}, ans{0};
    map<ll,int> mp;
    mp[0] = 1;
    FOR(i,0,n-1) {
        cin >> tmp;
        sum += tmp;
        ans += mp[sum-x];
        mp[sum]++;
    }
    cout << ans;
}