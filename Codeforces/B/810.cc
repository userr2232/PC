#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    long long n, f;
    cin >> n >> f;
    long long k, l;
    multimap<long long, pair<long long, long long>> m;
    for(long long i = 0; i < n; ++i) {
        cin >> k >> l;
        m.insert({-max((long long)0, min(2*k, l) - min(k, l)), {min(2*k, l), min(k, l)}});
    }
    long long i = 0;
    long long res{0};
    for(auto [key, value] : m) {
        auto [increased, original] = value;
        if(i < f) {
            res += increased;
            ++i;
        }
        else res += original;
    }
    cout << res << endl;
}