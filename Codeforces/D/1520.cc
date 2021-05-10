#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> AdjList;

int n;
vi A, memo;
vector<bool> taken, processed;
AdjList graph;

int dp(int i) {
    if(i == 0) return 0;
    int& ans = memo[i];
    if(ans != -1) return ans;
    ans = 0;
    FOR(j,0,i-1) if(A[j] < A[i] && !taken[j] && A[j]-A[i] == j-i) {
        taken[j] = true;
        ans += dp(j) + 1;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    return ans;
}

void process(int i) {
    processed[i] = true;
    for(int x : graph[i]) if(!processed[x]) process(x);
}

void solve() {
    cin >> n;
    memo.assign(n,-1);
    taken.assign(n, false);
    processed.assign(n, false);
    A.assign(n, 0);
    graph = vector<vector<int>>(n);
    FOR(i,0,n-1) cin >> A[i];
    int ans{0};
    FOR(i,0,n-1) {
        if(!processed[i]) ans += dp(i), process(i);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}