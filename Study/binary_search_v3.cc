#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
bool valid(int x) {
    // bool
}
int main() {
    int n; cin >> n;
    vi v(n);
    for(auto&e : v) cin >> e;
    int x{-1};
    for(int b = n/2; b >= 1; b/=2)
        while(x+b < n && !valid(x+b)) x += b;
    int k{x+1};
    cout << k << endl;
    return 0;
}