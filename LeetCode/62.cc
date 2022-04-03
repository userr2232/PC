class Solution {
    vector<vector<int>> memo;
    
    int dp(int m, int n) {
        int& ans = memo[m][n];
        if(ans != -1) return ans;
        ans = 0;
        if(m == 1 && n == 1) return ans = 1;
        if(m == 1) return ans = dp(1, n-1);
        if(n == 1) return ans = dp(m-1, 1);
        return ans = dp(m-1, n) + dp(m, n-1);
    }
    
public:
    int uniquePaths(int m, int n) {
        memo.assign(m+1, vector<int>(n+1, -1));
        return dp(m, n);
    }
};