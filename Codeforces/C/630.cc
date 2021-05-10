#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    cout << (1LL<<(n+1))-2 << "\n";
}