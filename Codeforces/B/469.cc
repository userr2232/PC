#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool intersect(pair<int,int> in1, pair<int,int> in2) {
    if(in1.first > in2.first) swap(in1, in2);
    auto [a, b] = in1;
    auto [c, d] = in2;
    if(a == c || b >= c) return true;
    return false;
}

int check(vector<pair<int,int>>& z_times, vector<pair<int,int>>& x_times, int t) {
    for(auto [cj, dj] : x_times) {
        for(auto [ai, bi] : z_times) {
            if(ai > dj + t) break;
            if(intersect({t + cj, t + dj}, {ai, bi})) return 1;
        }
    }
    return 0;
}

int main() {
    int p, q, l, r, a, b, c, d;
    cin >> p >> q >> l >> r;
    vector<pair<int,int>> z_times(p), x_times(q);
    for(int i = 0; i < p; ++i) {
        cin >> a >> b;
        z_times[i] = {a, b};
    }
    for(int i = 0; i < q; ++i) {
        cin >> c >> d;
        x_times[i] = {c, d};
    }
    int answer{0};
    for(int t = l; t <= r; ++t) {
        answer += check(z_times, x_times, t);
    }
    cout << answer << endl;
}