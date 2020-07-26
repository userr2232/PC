#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

void solve(string s, const vector<int>& b) {
    sort(s.begin(), s.end(), greater<char>());
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for(int i = 0; i < b.size(); ++i) {
        pq.push(b[i]);
    }

}

int main() {
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        vector<int> v(m);
        solve(s, v);
    }
    return 0;
}