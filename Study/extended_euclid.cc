#include <iostream>
#include <tuple>

using namespace std;
// ax + by = gcd(a, b) = gcd(b, a%b)
// bx' + (a%b)y' = gcd(b, a%b)
// bx' + (a-a/b*b)y' = gcd(b, a%b)
// ay' + b(x'-a/by') = gcd(b, a%b) = gcd(a, b)

tuple<int,int,int> gcd(int a, int b) {
    if(b == 0) return {1, 0, a};
    int x, y, g;
    tie(x, y, g) = gcd(b, a%b);
    return {y, x-a/b*y, g};
}

int main() {
    int x, y, g;
    // 12x + 30y = 6
    tie(x, y, g) = gcd(12, 30);
    cout << "x: " << x << " y: " << y << " gcd(12, 30): " << g << endl;
    return 0;
}