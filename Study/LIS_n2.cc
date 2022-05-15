//-7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4
#include <iostream>
#include <vector>
using namespace std;

int LIS(int i, vector<int> const& A, vector<int>& memo) {
    if(i == A.size()) return 0;
    int& ans = memo[i];
    if(ans != -1) return ans;
    ans = 1;
    for(int j = i+1; j < A.size(); ++j) if(A[j] > A[i])
        ans = max(ans, 1+LIS(j, A, memo));
    return ans;
}

int main() {
    vector<int> A = {20, -7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4};
    vector<int> memo(A.size(), -1);
    int ans{0};
    for(int k = 0; k < A.size(); ++k)
        ans = max(ans, LIS(k, A, memo));
    cout << ans << endl;
}