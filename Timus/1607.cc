#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c <= a) cout << a << endl;
    else
    while(1) {
        a += b;
        if(a >= c) { cout << c << endl; break; }
        c -= d;
        if(c <= a) { cout << a << endl; break; }
    }
}