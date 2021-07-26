#include <iostream>
#include <iomanip>
using namespace std;

double t, p, C;
bool eco;

bool charged(double x) {
    return p - x * C > 0;
}

int main() {
    cin >> t >> p;
    if(p >= 20) C = (double) (100-p)/t;
    else {
        eco = true;
        C = (60 - p) / t;
    }
    cout << setprecision(8) << fixed;
    if(eco) cout << p / C << endl;
    else cout << (p - 20) / C + 40 / C << endl;
}