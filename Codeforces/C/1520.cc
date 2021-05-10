#include <iostream>
#include <vector>
using namespace std;

int i, n, num;
vector<vector<int>> matrix;

void fill(int kr, int kc) {
    while(kr < n && kc < n)
        matrix[kr++][kc++] = ++num;
}

void print_matrix() {
    for(auto row : matrix) {
        for(auto val : row) cout << val << " ";
        cout << "\n";
    }
}

void solve() {
    cin >> n;
    matrix = vector<vector<int>>(n, vector<int>(n, 0));
    if(n == 2) { cout << "-1\n"; return; }
    num = 0;
    fill(0, 0);
    i = 1;
    for(;i < n; ++i) {
        int k = i;
        fill(k, 0);
        fill(0, k);
    }
    print_matrix();
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}