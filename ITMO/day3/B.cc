#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
vector<int> v, p, dp;
int n; 

int LIS(int i) {
    int& ans = dp[i];
    if(ans != -1) return ans;
    ans = 1;
    FOR(j,0,i-1) if(v[j] < v[i] && LIS(j)+1 > ans) {
        ans = dp[j] + 1;
        p[i] = j;
    }
    return ans;
}

void print_LIS(int i) {
    if(p[i] == -1) { if(i != n) cout << v[i]; return; }
    print_LIS(p[i]);
    if(i != n) cout << " " << v[i];
}

int main() {
    cin >> n;
    v.resize(n);
    dp.assign(n+1,-1), p.assign(n+1,-1);
    for(auto& e: v) cin >> e;
    v.push_back(1e9+1);
    cout << LIS(n)-1 << endl;
    print_LIS(n);
}