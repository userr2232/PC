#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi factors(int n) {
    vi f;
    for(int x = 2; x*x <= n; ++x) while(n%x == 0) f.push_back(x), n/=x;
    if(n > 1) f.push_back(n);
    return f;
}

int main() {
    int n; cin >> n;
    auto v = factors(n);
    for(auto e : v) cout << e << " ";
    return 0;
}