#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double r1{.0}, p1{.0}, p2{6000.}, t, A, B;
    cin >> n;
    while(n--) {
        cin >> t;
        r1 = max(r1, t);
    }
    cin >> n;
    while(n--) {
        cin >> t;
        p1 = max(p1, t);
    }
    cin >> n;
    while(n--) {
        cin >> t;
        p2 = min(p2, t);
    }
    cin >> A >> B;
    cout << setprecision(7) << endl;
    cout << fixed;
    cout << r1 / sqrt(1 + (A * p2) / (B * p1)) << endl;
}