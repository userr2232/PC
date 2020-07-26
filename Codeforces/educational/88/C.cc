#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int INF = 1e9;
    int T;
    cin >> T;
    while(T--) {
        int h, c,  t;
        cin >> h >> c >> t;
        if(h <= t) {
            cout << 1 << endl;
        }
        else if((h + c) / 2.0 == t || (h > t && c > t)) {
            cout << 2 << endl;
        }
        else {
            double mn = INF;
            double last = INF;
            int x = 0;
            while(mn > t) {
                last = mn;
                x++;
                mn = ((x + 1)*h + x*c) * 1.0 / (2*x + 1);
            }
            cout << (abs(t - mn) < abs(t - last) ? 2*(x--) + 1 : 2*x + 1) << endl;
        }
    }

    return 0;
}