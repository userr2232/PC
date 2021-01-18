#include <iostream>

using namespace std;

long long calc(long long k, long long x) {
    return k * (k + 1) / 2 - x * (x - 1) / 2;
}

int main() {
    long long n, k;
    cin >> n >> k;
    --k; --n;
    long long low{1}, high{k}, x{(low + high) / 2}, ans;
    if(n == 0) {
        cout << 0 << endl;
    }
    if(k * (k + 1) / 2 >= n) {
        while(low < high) {
            x = (low + high) / 2;
            ans = calc(k, x);
            if(ans <= n)
                high = x;
            else if(ans > n)
                low = x + 1;
        }
        x = high;
        if(calc(k, x) < n) --x;
        cout <<  k - x + 1 << endl;
    }
    else
        cout << -1 << endl;

    return 0;
}