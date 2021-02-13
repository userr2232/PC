#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    char c;
    cin >> n >> m >> c;
    vector<string> v(n + 2, string(m + 2, '.'));
    string tmp;
    for(int i = 1; i <= n; ++i) {
        cin >> tmp;
        v[i] = "." + tmp + ".";
    }
    set<char> s;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(v[i][j] == c || v[i][j] == '.')
                continue;
            if(v[i][j-1] == c || v[i][j+1] == c || v[i+1][j] == c || v[i-1][j] == c)
                s.insert(v[i][j]);
        }
    }
    cout << s.size() << endl;
}