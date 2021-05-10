#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n, t1, t2, k;
    cin >> n >> t1 >>  t2 >> k;
    int a, b;
    set<pair<double, int>> length_id;
    for(int i = 1; i <= n; ++i) {
        cin >> a >> b;
        double length = max(t1 * (100 - k) / 100.0 * a + t2 * b, t1 * (100 - k) / 100.0 * b + t2 * a);
        length_id.insert({-length, i});
    }
    cout << setprecision(2);
    int i = 0;
    for(auto x: length_id) {
        auto [length, id] = x;
        cout << id << " " << fixed << -length << endl;
    }
    return 0;
}