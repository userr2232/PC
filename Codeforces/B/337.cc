#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    long a, b, c, d; cin >> a >> b >> c >> d;
    double h1 = a, h2 = 1.0 * c * b / d;
    double v1 = 1.0 * a / c, v2 = b;
    if(h2 <= a) {
        int N = a * d - c * b, D = a * d;
        int g = gcd(N, D);
        cout << N / g << "/" << D / g << endl;
    }
    else {
        int N = b * c - d * a, D = b * c;
        int g = gcd(N, D);
        cout << N / g << "/" << D / g << endl;
    }
    return 0;
}