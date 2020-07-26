#include <iostream>
#include <limits>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if((n - 1)/ 2 + 1 >= k) cout << 2 * k - 1 << endl;
    else cout << 2 * (k - n / 2 - (n % 2)) << endl;
} 