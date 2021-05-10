#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

bool valid(int n, int m, pair<long long, long long> pos) {
    auto [row, col] = pos;
    return row >= 1 && row <= n && col >= 1 && col <= m;
}

pair<long long, long long> compute_pos(long long magnitude, pair<long long,long long> pos, pair<long long, long long> dir) {
    return {dir.first * magnitude + pos.first, dir.second * magnitude + pos.second};
}

int compute_steps(int n, int m, pair<long long,long long>& pos, pair<long long,long long> dir) {
    auto [row, col] = pos;
    auto [dr, dc] = dir;
    long long low{0}, high{(long long)1e9};
    long long mid{(long long)ceil((low + high) / 2.0)};
    while(low < high) {
        if(valid(n, m, compute_pos(mid, pos, dir))) low = mid;
        else high = mid-1;
        mid = ceil((low + high) / 2.0);
    }
    pos = compute_pos(mid, pos, dir);
    return mid;
}

int main() {
    int n, m;
    cin >> n >> m;
    int row, col;
    cin >> row >> col;
    int k;
    cin >> k;
    int dr, dc;
    long long steps{0};
    pair<long long, long long> pos = {row, col};
    for(int i = 0; i < k; ++i) {
        cin >> dr >> dc;
        steps += compute_steps(n, m, pos, {dr, dc});
    }
    cout << steps << endl;

    return 0;
}