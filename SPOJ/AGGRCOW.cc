#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<long long>& pos, long long C, long long x) {
    auto prev = -2e9;
    for(auto p : pos) {
        if(p - prev >= x) {
            prev = p;
            if(--C == 0)
                return true;
        }
    }
    return false;
}

int main() {
    int TC;
    long long N, C;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    while(TC--) {
        cin >> N >> C;
        vector<long long> pos(N);
        while(N--)
            cin >> pos[N];
        sort(pos.begin(), pos.end());
        N = pos.size();
        long long low{pos[0]}, high{pos[N-1]}, x{(low + high) / 2};
        while(low < high) {
            if(possible(pos, C, x))
                low = x;
            else
                high = x - 1;
            x = (low + high + 1) / 2;
        }
        cout << x << endl;
    }
}