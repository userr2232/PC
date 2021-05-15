#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
int sieve[10010];
vi factors(int n) {
    vi f;
    int x = sieve[n];
    while(n > 1) {
        if(n % x == 0) f.push_back(x), n /= x;
        else x = sieve[n];
    }
    return f;
}

int main() {
    int n; cin >> n;
    FOR(x,2,n) {
        if(sieve[x]) continue;
        FOR(u,1,n/x) if(!sieve[u*x]) sieve[u*x] = x;
    }
    auto v = factors(n);
    for(auto x : v) cout << x << " ";
    cout << "\n";
}