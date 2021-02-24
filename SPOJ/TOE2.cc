#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>

using namespace std;

bool check_row(string s) {
    if(s[0] == '.') return false;
    return s == string(3, s[0]);
}

bool check_main_d(vector<string>& v) {
    if(v[0][0] == '.') return false;
    return v[0][0] == v[1][1] && v[1][1] == v[2][2];
}

bool check_second_d(vector<string>& v) {
    if(v[2][0] == '.') return false;
    return v[2][0] == v[1][1] && v[1][1] == v[0][2];
}

bool check_column(vector<string>& v, int c) {
    if(v[0][c] == '.') return false;
    return v[0][c] == v[1][c] && v[1][c] == v[2][c];
}

bool has_ended(string s) {
    bool b = true;
    for(auto c : s) {
        if(c == '.') { b = false; break; }
    }
    if(b) return true;
    vector<string> v = {s.substr(0, 3), s.substr(3, 3), s.substr(6, 3)};
    for(auto r : v) {
        if(check_row(r)) return true;
    }
    for(int i = 0; i < 3; ++i) {
        if(check_column(v, i)) return true;
    }
    if(check_main_d(v)) return true;
    if(check_second_d(v)) return true;
    return false;
}

void check(string board) {
    string ans = "invalid";
    map<bool, char> plays = {{true, 'X'}, {false, 'O'}};
    queue<pair<string, bool>> q;
    q.push({".........", true});
    while(q.size()) {
        auto [s, b] = q.front();
        q.pop();
        if(s == board) { ans = "valid"; break; }
        if(has_ended(s)) continue;
        for(int i = 0; i < 9; ++i) {
            if(s[i] != '.') continue;
            auto tmp = s;
            tmp[i] = plays[b];
            if(tmp[i] == board[i]) q.push({tmp, !b});
        }
    }
    cout << ans << endl;
}

int main() {
    string board;
    while(cin >> board, board != "end") {
        if(has_ended(board)) { check(board); }
        else { cout << "invalid" << endl; }
    }
}
