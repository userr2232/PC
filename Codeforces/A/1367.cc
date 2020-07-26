#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 


int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string ans = s.substr(0, min(2, int(s.size())));
        for(int i = 2; i < s.length() - 1; i+=2) {
            ans += s[i + 1];
        }
        cout << ans << endl;
    }
}