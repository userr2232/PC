#include <iostream>

using namespace std;

const long long mod = 1e9+7;

long long f(int n) {
    if(n <= 1) return 1;
    long long answer{1};
    while(n > 1) { 
        answer *= n % mod; 
        answer = answer % mod;
        n--;
    }
    return answer;
}

void solve() {
    int n, k; cin >> n >> k;
    cout << (((f(n) % mod) * ((1LL << (k - 1)) % mod)) % mod) << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
}