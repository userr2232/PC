#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef long long ll;

vector<string> matrix(8);
ll counter;

bool attacking(int r, int c) {
    FOR(i,0,7) if(matrix[r][i] == 'Q' || matrix[i][c] == 'Q') return true;
    FOR(i,1,7) {
        if(r+i < 8) {
            if(c-i>=0) { if(matrix[r+i][c-i] == 'Q') return true; }
            if(c+i<8) { if(matrix[r+i][c+i] == 'Q') return true; }
        }
        if(r-i >= 0) {
            if(c-i>=0) { if(matrix[r-i][c-i] == 'Q') return true; }
            if(c+i<8) { if(matrix[r-i][c+i] == 'Q') return true; }
        }
    }
    return false;
}
void solve(int r = 0) {
    if(r == 8) { ++counter; return; }
    FOR(c,0,7) {
        if(matrix[r][c] == '*' || matrix[r][c] == 'Q' || attacking(r, c)) continue;
        matrix[r][c] = 'Q';
        solve(r+1);
        matrix[r][c] = '.';
    }
}

int main() {
    FOR(j,0,7) cin >> matrix[j];
    solve();
    cout << counter << endl;
    return 0;
}