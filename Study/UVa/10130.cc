#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;

const int MAX_N{1010}, MAX_W{40};
int n, memo[MAX_N][MAX_W], V[MAX_N], W[MAX_N];

int dp(int id, int remW) {
    if(id == n || remW == 0) return 0;
    int& ans = memo[id][remW];
    if(ans != -1) return ans;
    if(W[id] > remW) return ans = dp(id+1, remW);
    return ans = max(dp(id+1, remW), V[id]+dp(id+1, remW-W[id]));
}

int main() {

    return 0;
}