#include <iostream>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<bool>> v(n+1, vector<bool>(n+1));
    int a, b;
    FOR(i,1,m) cin >> a >> b, v[a][b] = v[b][a] = true;
    FOR(i,1,n) {
        FOR(j,1,n) cout << v[i][j] << " ";
        cout << endl;
    }
}