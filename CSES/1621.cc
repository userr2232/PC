#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    sort(v.begin(), v.end());
    int ans{1};
    int cur = v[0];
    for(auto x : v) if(x != cur) cur = x, ans++;
    cout << ans;
}