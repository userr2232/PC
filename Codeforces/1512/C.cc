#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int a, b, other{0};
        cin >> a >> b;
        string str;
        cin >> str;
        int n = str.length();
        bool done = false;
        for(char x: str) {
            if(x == '0') --a;
            else if(x == '1') --b;
            else ++other;
        }
        for(int j = 0; j < n; ++j) {
            if(str[j] == '?' && str[n-1-j] != '?') {
                if(str[n-1-j] == '1') {
                    str[j] = '1';
                    --other;
                    --b;
                }
                else {
                    str[j] = '0';
                    --other;
                    --a;
                }
            }
            else if(str[j] != '?' && str[n-1-j] == '?') {
                if(str[j] == '1') {
                    str[n-1-j] = '1';
                    --other;
                    --b;
                }
                else {
                    str[n-1-j] = '0';
                    --other;
                    --a;
                }
            }
            else if(str[j] != '?' && str[n-1-j] != '?') {
                if(str[j] != str[n-1-j]) {
                    done = true;
                    cout << -1 << endl;
                    break;
                }
            }
        }
        if(done) continue;
        for(int j = 0; j < n; ++j) {
            if(str[j] == '?') {
                if(a > b) {
                    str[j] = '0';
                    str[n-1-j] = '0';
                    if(j != n-j-1) {
                        other -= 2;
                        a -= 2;
                    }
                    else {
                        --other;
                        --a;
                    }
                }
                else {
                    str[j] = '1';
                    str[n-1-j] = '1';
                    if(j != n-1-j) {
                        other -= 2;
                        b -= 2;
                    }
                    else {
                        --other;
                        --b;
                    }
                }
            }
        }
        if(a == 0 && b == 0 && other == 0) cout << str << endl;
        else {
            // cout << -1 << " because " << str << " a: " << a << " b: " << b << " other: " << other << endl;
            cout << -1 <<endl;
        }
    }

    return 0;
}