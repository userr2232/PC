#include <iostream>

using namespace std;

int main() {
    long long n, a{1}, b{1}, mod = 1e9 + 7;
    cin >> n;
    for(int i = 0; i < n*3; ++i)
        a = a * 3 % mod;
    for(int i = 0; i < n; ++i)
        b = b * 7 % mod;

    cout << (a - b + mod) % mod << endl;

    return 0;
}