#include <iostream>

using namespace std;

void solve(long long n) {
    cout << n << " ";
    if(n == 1) return;
    if(n % 2) n = n * 3 + 1;
    else n /= 2;
    solve(n);
}

int main() {
    long long n; cin >> n;
    solve(n);
    cout << endl;
    return 0;
}