#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        unsigned long long n, tmp;
        cin >> n;
        tmp = n;
        int count = 0;
        while(tmp) {
            count += tmp & 1;
            tmp >>= 1;
        }
        cout << 2 * n - count  << endl;
    }
}