#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multimap<int, int> mp;
    while(m--) {
        int a, b;
        cin >> a >> b;
        mp.insert({-b, -a});
    }
    int ans{0};
    for(auto [k, v] : mp) {
        if(-v >= n) {
            ans += -k * n;
            break;
        }
        else {
            int tmp = -k * -v;
            n -= -v;
            ans += tmp;
        }
    }
    cout << ans << endl;
}