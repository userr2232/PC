#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<long long> sum(vector<long long> v) {
    size_t n = v.size();
    vector<long long> res(n+1);
    res[0] = 0;
    for(long long i = 1; i <= n; ++i)
        res[i] = res[i-1] + v[i-1];
    return res;
}

pair<vector<long long>, vector<long long>> compute_vectors(vector<long long> v) {
    auto v1 = sum(v);
    sort(v.begin(), v.end());
    return {v1, sum(v)};
}

int main() {
    long long n, m;
    cin >> n;
    vector<long long> v(n);
    for(long long i = 0; i < n; ++i) cin >> v[i];
    cin >> m;
    auto [v1, v2] = compute_vectors(v);
    long long type, l, r;
    for(long long i = 0; i < m; ++i) {
        cin >> type >> l >> r;
        if(type == 1) cout << v1[r] - v1[l-1];
        else cout << v2[r] - v2[l-1];
        cout << endl;
    }
}