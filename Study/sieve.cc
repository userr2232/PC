#include <iostream>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
bool sieve[1010];
int main() {
    int n; cin >> n;
    sieve[0] = sieve[1] = true;
    FOR(x,2,n) {
        if(sieve[x]) continue;
        FOR(u,2,n/x) sieve[u*x] = true;
    }
    FOR(x,2,n) if(!sieve[x]) cout << x << " ";
    cout << "\n";
    return 0;
}