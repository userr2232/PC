#include <iostream>
using namespace std;
int main() {
    long long n, tmp; cin >> n;
    long long nn1 = n*(n+1) / 2;
    long long sum{0};
    for(int i = 0; i < n-1; ++i) {
        cin >> tmp;
        sum += tmp;
    }
    cout << nn1 - sum << endl;
    return 0;
}