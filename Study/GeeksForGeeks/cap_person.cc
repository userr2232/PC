// https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
const int MOD = 1e9+7;
vector<vector<int>> dp((1<<10)+1, vector<int>(100+1, -1));
vector<vector<int>> persons_with_cap(100+1);
int allmask;

int countWays(int mask, int id) {
    if(mask == allmask) return 1;
    if(id > 100) return 0;
    int& ans = dp[mask][id];
    if(ans != -1) return ans;
    ans = countWays(mask, id+1);
    int sz = persons_with_cap[id].size();
    for(int j = 0; j < sz; ++j) {
        if(mask & (1 << persons_with_cap[id][j])) continue;
        else ans += countWays(mask | (1 << persons_with_cap[id][j]), id+1);
        ans %= MOD;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        istringstream iss(str);
        int t;
        while(cin >> t) taken[t] = false, persons_with_cap[t].push_back(i);
    }
    allmask = (1 << n) - 1;
    countWays(0, 1);
    return 0;
}