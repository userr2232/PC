#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, k, x{0};
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        x += r - l + 1;
    }
    cout << ceil(1.0 * x / k) * k - x << endl;
}