#include <iostream>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll A[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    FOR(i,1,n) cin >> A[i], A[i] += A[i-1];
    int a, b;
    FOR(i,1,q) cin >> a >> b, cout << A[b] - A[a-1] << endl;
    return 0;
}