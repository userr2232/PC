#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
const int N = 1e5+10;
int sieve[N];

vi factors(int n) {
    int x = sieve[n];
    vi f;
    while(n > 1) {
        if(n % x == 0) f.push_back(x), n /= x;
        else x = sieve[n];
    }
    return f;
}

void build_extended_sieve(int n) {
    sieve[0] = sieve[1] = 1;
    FOR(x,2,n) {
        if(sieve[x]) continue;
        FOR(u,2,n/x) if(!sieve[u*x]) sieve[u*x] = x;
    }
}

int main() {
    int n; cin >> n;
    build_extended_sieve(n);
    auto v = factors(n);
    for(auto e: v) cout << e << " ";
    return 0;
}