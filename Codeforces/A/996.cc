#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9+1
using namespace std;
typedef vector<int> vi;
vi memo;
vi denominations = {1, 5, 10, 20, 100};

int main() {
    int n; cin >> n;
    int ans{0};
    for(int i = denominations.size()-1; i >= 0 && n > 0; --i) {
        int tmp = n / denominations[i];
        ans += tmp;
        n -= tmp * denominations[i];
    }
    cout << ans << endl;
    return 0;
}