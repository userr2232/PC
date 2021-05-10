#include <iostream>
#include <string>
using namespace std;

void solve() {
    string str; cin >> str;
    int ans = 9 * (str.length()-1);
    for(int i = 0; i < 9; ++i)
        if(str >= string(str.length(),char('1'+i))) ans++;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}