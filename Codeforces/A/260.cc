#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, n;
    cin >> a >> b >> n;
    a *= 10;
    n--;
    for(int i = 0; i <= 9; ++i) {
        if((a + i) % b == 0) {
            cout << (a + i);
            for(int i = 0; i < n; ++i) {
                cout << 0;
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}