#include <iostream>
using namespace std;

int modpow(int a, int b, int m) {
    if(b == 0) return 1;
    long long u = modpow(a, b/2, m);
    u = (u * u) % m;
    if(b % 2) u *= a;
    return u % m;
}

int main() {
    int a, b, m;
    cin >> a >> b >> m;
    cout << modpow(a, b, m) << endl;
}