#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
int main() {
    int n, x; cin >> n >> x;
    vi v(n);
    for(auto&e : v) cin >> e;
    int a{0}, b{n-1};
    while(a <= b) {
        int k = (a + b) / 2;
        if(v[k] == x) {
            // found
            return 0;
        }
        if(v[k] < x) a = k-1;
        else b = k+1;
    }
    return 0;
}