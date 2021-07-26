#include <iostream>
using namespace std;
int main() {
    string s; cin >> s;
    int n = s.size();
    int countC{0}, countA{0};
    long long ans{0};
    for(auto c: s) if(c == 'c') ++countC;
    for(int i = 0; i < n; ++i) {
        if(s[i] != 'b') {
            if(s[i] == 'a') ++countA;
            if(s[i] == 'c') --countC;
            continue;
        }
        ans += countA * countC;
    }
    cout << ans << endl;
}