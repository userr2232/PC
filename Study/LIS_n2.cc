//-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4, 99
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
int memo[10010];
vi A;
int LIS(int i) {
    int& ans = memo[i];
    if(ans != -1) return ans;
    ans = 1;
    FOR(j,0,i-1) if(A[j] < A[i]) ans = max(ans, LIS(j)+1);
    return ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    A = {-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4, 99};
    cout << LIS(A.size()-1) << endl;
    return 0;
}