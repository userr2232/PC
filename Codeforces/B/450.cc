#include <iostream>

using namespace std;

long long f(long long n, long long x , long long y) {
    if(n == 1)
        return x;
    else if(n == 2)
        return y;
    else if(n == 3)
        return y - x;
    else return -f((n - 3), x, y);
}

int main() {
    long long x, y, n;
    cin >> x >> y >> n;
    const long long M = 1e9 + 7;
    long long ans = f(n, x ,y) % M;
    if (ans < 0) ans += M;
    cout << ans << endl;
    return 0;
}