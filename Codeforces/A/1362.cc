#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a, b;
        cin >> a >> b;
        if(a == b) {
            cout << 0 << endl;
            continue;
        }
        if(a % b != 0 && b % a != 0) {
            cout << -1 << endl;
            continue;
        }
        if(b > a) swap(a, b);
        long long div = a / b;
        bool k = true;
        int count = 0;
        while(div > 1) {
            if(div & 1) {
                cout << -1 << endl;
                k = false;
                break;
            }
            div = div >> 1;
            count++;
        }
        if(k) {
            int tmp = 0;
            if(count % 3) {
                tmp ++;
                count -= count % 3;
            }
            if(count > 0)
                tmp += count / 3;
            cout << tmp << endl;
        }
    }
    return 0;
}