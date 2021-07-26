#include <iostream>
using namespace std;

int main() {
    int n, S; cin >> n >> S;
    int ans{0};
    while(S) {
        if(S < n) { ans++; break; }
        ans += S/n;
        S %= n;
        n--;
    }
    cout << ans << endl;
}