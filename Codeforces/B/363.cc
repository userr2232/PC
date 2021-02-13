#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void sum(vector<int>& v) {
    for(int i = 1; i < v.size(); ++i)
        v[i] += v[i-1];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> v[i];
    sum(v);
    int m{numeric_limits<int>::max()}, p{0};
    for(int i = k; i <= n; ++i) {
        auto t = v[i] - v[i - k];
        if(t < m) {
            m = t;
            p = i - k + 1;
        }
    }
    cout << p << endl;
}