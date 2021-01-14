#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int sum(vector<vector<char>>&v, int i, int j) {
    unordered_map<char,int> vals = {{'#', 1}, {'.', 0}};
    return vals[v[i][j]] + vals[v[i+1][j]] + vals[v[i][j+1]] + vals[v[i+1][j+1]];
}

vector<vector<int>> conv2x2(vector<vector<char>>& v) {
    vector<vector<int>> c;
    for(int i = 0; i < 3; ++i) {
        vector<int> tmp;
        for(int j = 0; j < 3; ++j)
            tmp.push_back(sum(v, i, j));
        c.push_back(tmp);
    }
    return c;
}

int main() {
    vector<vector<char>> m(4, vector<char>(4));
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            cin >> m[i][j];
    auto v = conv2x2(m);
    auto b = false;
    for(auto row : v) {
        for(auto e : row) {
            if(e != 2) {
                b = true;
                break;
            }
        }
        if(b) break;
    }
    cout << (b ? "YES" : "NO") << endl;
}