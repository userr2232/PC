#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> boys(n); for(auto& e : boys) cin >> e;
    int m; cin >> m;
    vector<int> girls(m); for(auto& e : girls) cin >> e;
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int ans{0};
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        if(abs(boys[i]-girls[j]) <= 1) {
            girls[j] = 2e9;
            ans++;
            break;
        }
    }
    cout << ans << endl;
}