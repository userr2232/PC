#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    if(a < b) swap(a, b);
    int num = 6 - a + 1;
    int den = 6;
    int d = gcd(num, den);
    cout << num / d << "/" << den / d << endl;

    return 0;
}