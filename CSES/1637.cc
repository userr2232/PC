#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e6+10;
int memo[N];

int dp(int x) {
    if(x == 0) return 0;
    if(x < 10) return 1;
    int& ans = memo[x];
    if(ans != -1) return ans;
    ans = 2e9;
    int tmp = x;
    while(tmp) {
        int d = tmp%10;
        if(d) ans = min(ans, 1+dp(x-d));
        tmp /= 10;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    memset(memo,-1,sizeof memo);
    cout << dp(n) << endl;
    return 0;
}