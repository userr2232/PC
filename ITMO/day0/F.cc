#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define invFOR(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
const int N = 1e5+10;
int b[N], c[N], bc[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    int n = s.size();
    invFOR(i,n-1,0) b[i] = b[i+1] + (s[i] == 'b'), c[i] = c[i+1] + (s[i] == 'c');
    invFOR(i,n-1,0) bc[i] = 1LL * (s[i] == 'b') * c[i+1] + bc[i+1];
    long long ans{0};
    FOR(i,0,n-1) if(s[i] == 'a') ans += bc[i];
    cout << ans << endl;
}