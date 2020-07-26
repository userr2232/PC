#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned int n;
    while(cin >> n, n != 0) {
        int sq = sqrt(n);
        if(sq * sq == n) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}