#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#define min(a,b,c) min(a,min(b,c))
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
typedef pair<int,int> ii;
const int N = 1e6+10, INF = 2e9;
int n;
vector<ii> memo;

ii min_operations(int x = 1) {
    if(x > n) return {INF, -1};
    auto &ans = memo[x];
    if(ans.first != -1) return ans;
    if(x == n) return ans = {0, -1};
    ans = min(min_operations(x+1), min_operations(x*2), min_operations(x*3));
    int p;
    if(x+1 <= n && ans.first == memo[x+1].first) p = x+1;
    if(x*2 <= n && ans.first == memo[x*2].first) p = x*2;
    if(x*3 <= n && ans.first == memo[x*3].first) p = x*3;
    return ans = {ans.first+1, p};
}

int main() {
    cin >> n;
    memo.assign(N, {-1,-1});
    auto [ops, p] = min_operations();
    cout << ops << endl;
    cout << 1 << " ";
    while(p != -1) cout << p << " ", p = memo[p].second;
    return 0;
}