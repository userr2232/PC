#include <iostream>
#define LSOne(S) ((S) & -(S))
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
const int MAX_N = 11;
int dist[MAX_N][MAX_N], memo[MAX_N][1<<(MAX_N-1)];

int dp(int u, int mask) {
    if(mask == 0) return dist[u][0];
    int& ans = memo[u][mask];
    if(ans != -1) return ans;
    ans = 2e9;
    int m = mask;
    while(m) {
        int two_pow_v = LSOne(m);
        int v = __builtin_ctz(two_pow_v)+1;
        ans = min(ans, dist[u][v] + dp(v, mask^two_pow_v));
        m -= two_pow_v;
        cerr << m << endl;
    }
    return ans;
}

int main() {
    int TC; cin >> TC;
    while(TC--) {
        int xsize, ysize; cin >> xsize >> ysize;
        int x[MAX_N], y[MAX_N];
        cin >> x[0] >> y[0];
        int n; cin >> n;
        FOR(i,1,n) cin >> x[i] >> y[i];
        FOR(i,0,n) FOR(j,i,n) dist[i][j] = dist[j][i] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
        memset(memo,-1,sizeof memo);
        cout << "The shortest path has length " << dp(0,(1<<n)-1) << endl;
    }
}