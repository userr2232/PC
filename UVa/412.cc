#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int N;
    while(cin >> N, N) {
        vector<int> v(N);
        int count{0};
        for(int i = 0; i < N; ++i)
            cin >> v[i];
        for(int i = 0; i < N - 1; ++i) {
            for(int j = i + 1; j < N; ++j) {
                if(gcd(v[i], v[j]) == 1) ++count;
            }
        }
        if(count)
            cout << fixed << setprecision(6) << sqrt((double)6 * (N * (N - 1) / 2) / count);
        else
            cout << "No estimate for this data set.";
        cout << endl;
    }
}