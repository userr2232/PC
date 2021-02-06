#include <iostream>
#include <vector>

using namespace std;

vector<int> types = {0, 1, 2}; // rest, sport, write
vector<int> v;
vector<vector<int>> memo;

int DP(int prev_type, int i) {
    int m = 101;
    if(i == v.size()) return 0;
    if(memo[prev_type][i] != -1) return memo[prev_type][i];
    if(v[i] == 0) {
        memo[prev_type][i] = DP(0, i + 1) +  1;
        return memo[prev_type][i];
    }
    for(auto type : types) {
        if(type && type == prev_type) continue;
        int tmp = DP(type, i + 1);
        if(!(type == 1 && v[i] >= 2 || type == 2 && v[i]%2 || type == 3)) ++tmp;
        if(tmp < m) m = tmp;
    }
    memo[prev_type][i] = m;
    return m;
}

int main() {
    int n;
    cin >> n;
    memo = vector<vector<int>>(3, vector<int>(n, -1));
    for(int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << DP(0, 0) << endl;
    return 0;
}