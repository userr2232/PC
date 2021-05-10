#include <iostream>
#include <vector>
using namespace std;
vector<int> counter;

void solve() {
    counter.assign(26, 0);
    int n; cin >> n;
    string str; cin >> str;
    counter[str[0]-'A']++;
    for(int i = 1; i < n; ++i) {
        if(str[i] == str[i-1]) continue;
        if(++counter[str[i]-'A'] > 1) { cout << "NO\n"; return; }
    }
    cout << "YES\n"; return;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}