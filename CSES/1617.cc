#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int ans{1};
    while(n--) {
        ans <<= 1;
        ans %= (int) 1e9+7;
    }
    cout << ans << endl;
}