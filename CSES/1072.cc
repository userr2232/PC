#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    for(long long k = 1; k <= n; ++k) {
        long long a1 = k*k, a2 = a1*(a1-1) / 2;
        if(k > 2) a2 -= 4 * (k-1)*(k-2);
        cout << a2 << endl;
    }
    return 0;
}