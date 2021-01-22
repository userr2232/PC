#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N, tmp;
    cin >> N;
    int r{0}, f, c;
    vector<int> v(N), res(N), d(N);
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
        f = floor(1.0 * v[i] / 2);
        c = ceil(1.0 * v[i] / 2);
        if(abs(r + f) < abs(r + c)) {
            res[i] = f;
        }
        else {
            res[i] = c;
        }
        if(res[i] > v[i] / 2.0)
            d[i] = 1;
        else if(res[i] < v[i] / 2.0)
            d[i] = -1;
        r += res[i];
    }
    if(r > 0) {
        for(int i = 0; i < res.size() && r > 0; ++i) {
            if(d[i] == 1) {
                --res[i];
                --r;
            }
        }
    }
    else if(r < 0) {
        for(int i = 0; i < res.size() && r < 0; ++i) {
            if(d[i] == -1) {
                ++res[i];
                ++r;
            }
        }
    }
    for(auto x : res) {
        cout << x << endl;
    }
}