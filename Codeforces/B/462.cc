#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<char,int> m;
    while(n--){
        char x;
        cin >> x;
        m[x] = m.count(x) == 0 ? 1 : m[x] + 1;
    }
    vector<pair<int, char>> v;
    for(auto const& [key, value] : m)
        v.push_back({value, key});
    sort(v.begin(), v.end(), greater<pair<int, char>>());
    long long coins = 0;
    for(int i = 0; i < v.size() && k > 0; ++i) {
        coins += 1LL * min(v[i].first, k) * min(v[i].first, k);
        k = max(k - v[i].first, 0);
    }
    cout << coins << endl;
    return 0;
}