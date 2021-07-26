#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n; cin >> n;
    int tmp, ans{0}, sum{0};
    while(n--) {
        cin >> tmp;
        sum += tmp;
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    cout << ans << endl;
}