#include <iostream>

using namespace std;

int f(int x) {
    return 5 * x * (x + 1) / 2;
}

int main() {
    int n, k;
    cin >> n >> k;
    int x = 1;
    for(int b = n/2; b >= 1; b /= 2) {
        while(b + x <= n && f(x + b) + k <= 60 * 4) {
            x += b;
        }
    }
    if(f(x) + k > 240) x--;
    cout << x << endl;

    return 0;
}