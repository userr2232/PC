#include <iostream>

using namespace std;

int main() {
    int p, c, a, b;
    cin >> p >> c >> a >> b;
    if(a < b)
        cout << 2 * c + (b - a - 1) * (2 * c + p) << endl;
    else
        cout << 2 * (c + p) + (a - b - 1) * (2 * c + p) << endl;
}