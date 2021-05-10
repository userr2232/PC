#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN{1010}, MAXW{40};
int N, memo[MAXN][MAXW], V[MAXN], W[MAXN];

int dp(int id, int remW) {
    if(id == N || remW == 0) return 0;
    int& ans = memo[id][remW];
    if(ans != -1) return ans;
    if(W[id] > remW) return dp(id+1, remW);
    ans = max(dp(id+1, remW), V[id] + dp(id+1, remW-W[id]));
    return ans;
}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> N;
        for(int i = 0; i < N-1; ++i) cin >> V[i] >> W[i];
        int G; cin >> G;
        int ans{0};
        while(G--) {
            int MW; cin >> MW;
            ans += dp(0, MW);
        }
        cout << ans << "\n";
    }
    return 0;
}