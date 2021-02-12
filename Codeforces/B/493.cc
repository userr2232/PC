#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

bool check(double d, int l, vector<int>& v) {
    size_t n{v.size()};
    for(int i = 1; i < n; ++i)
        if(v[i - 1] + d < v[i] - d)
            return false;
    if(v[0] - d > 0 || v[n - 1] + d < l) return false;
    return true;
}

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> as(n);
    for(int i = 0; i < n; ++i) cin >> as[i];
    sort(as.begin(), as.end());
    long double EPS{1e-10}, low{0}, high{(double)l};
    long double d;
    while(low < high - EPS) {
        d = (low + high) / 2;
        auto v = check(d, l, as);
        if(v) high = d;
        else low = d;
    }
    cout << fixed << setprecision(10) << d << endl;
}