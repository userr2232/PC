//-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4, 99
#include <iostream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
using namespace std;
int memo[10010];
int LIS(int i) {
    if(i == 0) return 1;
    int& ans = memo[i];
    if(ans != -1) return ans;
    ans = 1;
    FOR(j,0,i-1) if(A[j] < A[i]) ans = max(ans, LIS(j)+1);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memo, -1, sizeof memo);
    A = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4, 99};
    cout << LIS(A.size()-1) << "\n";
}