#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, tmp; cin >> n;
    int ans{0}, sum{0};
    for(int i = 0; i < n; ++i) {
        cin >> tmp;
        sum += tmp;
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    cout << ans << "\n";
    return 0;
}