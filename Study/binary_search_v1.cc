#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> v(n);
    for(auto& e : v) cin >> e;
    int a{0}, b{n-1};
    while(a <= b) {
        int m = a + (b-a)/2;
        if(v[m] == x) {
            // found
        }
        else if(v[m] < x) a = m+1;
        else b = m-1;
    }
}