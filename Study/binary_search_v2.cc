#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
int main() {
    int n, x; cin >> n >> x;
    vi v(n);
    for(auto& e: v) cin >> e;
    int k{0};
    for(int b = n/2; b >= 1; b/=2)
        while(k+b < n && v[k+b] <= x) k += b;
    if(v[k] == x) {
        // found
        return 0;
    }
    return 0;
}