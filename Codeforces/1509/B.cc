#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int Ts{0}, Ms{0};
    for(int i = 0; i < n; ++i) {
        if(str[i] == 'T') Ts++;
        else Ms++;
    }
    if(Ts != 2 * Ms) {
        cout << "NO" << endl;
        return;
    }
    int leftTs{0}, Mord{1};
    for(int i = 0; i < n; ++i) {
        if(str[i] == 'T') leftTs++;
        else {
            if(leftTs < Mord++) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    int rightTs{0}; Mord = 1;
    for(int i = n-1; i >= 0; --i) {
        if(str[i] == 'T') rightTs++;
        else {
            if(rightTs < Mord++) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}