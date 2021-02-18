#include <cctype>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

map<char, bool> other_hand;

int dist(char c, pair<int,int> p, map<char, vector<pair<int,int>>>& mp) {
    int m = 1000;
    for(auto [x1, y1] : mp[c]) {
        auto [x2, y2] = p;
        pair<int, int> d = {x2 - x1, y2 - y1};
        int d2 = d.first*d.first + d.second*d.second;
        m = min(m, d2);
    }
    return m;
}

int find_min_distance(char c, vector<pair<int,int>>& S, map<char, vector<pair<int,int>>>& mp) {
    int m = 1000;
    for(auto [f, s] : S) {
        auto d = dist(c, {f, s}, mp);
        m = min(m, d);
    }
    return m;
}

bool has_to_use_other_hand(vector<pair<int,int>>& S, map<char, vector<pair<int,int>>>& mp, int x, char c) {
    if(c >= 'a' && c <= 'z') return false;
    c = tolower(c);
    if(other_hand.count(c)) return other_hand[c];
    auto d = find_min_distance(c, S, mp);
    other_hand[c] = d > x*x;
    return other_hand[c];
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    string str;
    map<char, vector<pair<int,int>>> mp;
    vector<pair<int,int>> S;
    for(int i = 1; i <= n; ++i) {
        cin >> str;
        for(int j = 1; j <= m; ++j) {
            if(str[j-1] == 'S') S.push_back({i, j});
            else mp[str[j-1]].push_back({i, j});
        }
    }
    int q, count{0};
    cin >> q;
    string qs;
    cin >> qs;
    while(q--) {
        char c = qs[q];
        if(mp.count(tolower(c)) == 0 || c >= 'A' && c <= 'Z' && S.size() == 0) { cout << -1 << endl; return 0; }
        if(has_to_use_other_hand(S, mp, x, c)) ++count;
    }
    cout << count << endl;
}
