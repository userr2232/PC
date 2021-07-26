#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n, p;
    cout.precision(0);
    while(cin >> n >> p) cout << fixed << exp(log(p)/n) << "\n";
    return 0;
}