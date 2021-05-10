#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    while(cin >> n, n) {
        long long stan{0}, ollie{0};
        vector<long long> x(n, 0), y(n, 0);
        for(long long i = 0; i < n; ++i)
            cin >> x[i] >> y[i];
        long long cx{x[n>>1]}, cy{y[n>>1]};
        for(long long  i = 0; i < n; ++i) {
            auto dx = x[i] - cx;
            auto dy = y[i] - cy;
            if(dx * dy == 0) continue;
            else if (dx * dy > 0) ++stan;
            else ++ollie;
        }
        cout << stan << " " << ollie << endl;
    }
    return 0;
}