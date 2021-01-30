#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    vector<bool> v(n);
    int tmp;
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        if(tmp) v[i] = true;
    }
    --a; --n;
    int max_dist = max(a, n - a);
    int count{0};
    for(int i = 0; i <= max_dist; ++i) {
        int l{a - i}, r{a + i};
        if(l >= 0 && r <= n) { 
            if(v[l] && v[r]) {
                if(l == r) ++count; 
                else count += 2;
            }
        }
        else if(l >= 0 && r > n) { 
            if(v[l]) ++count;
        }
        else if(l < 0 && r <= n) { 
            if(v[r]) ++count;
        }
    }
    cout << count << endl;
}