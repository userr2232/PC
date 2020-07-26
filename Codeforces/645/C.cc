#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        long long xa, ya, xb, yb;
        cin >> xa >> ya >> xb >> yb;
        cout << (xb - xa) * (yb - ya) + 1 << endl;
    }
    return 0;
}