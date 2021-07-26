#include <iostream>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
const int N = 1e5+10;
int sieve[N];
void build_sieve(int n) {
    sieve[1] = sieve[0] = true;
    FOR(x,2,n) {
        if(sieve[x]) continue;
        FOR(u,2,n) sieve[x*u] = true;
    }
}

int main() {
    int n; cin >> n;
    build_sieve(n);
    FOR(i,0,n) if(!sieve[i]) cout << i << " ";
    return 0;
}