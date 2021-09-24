class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, n+2);
        dp[0] = 0;
        for(int i = 0; i <= n; ++i) for(int j = max(i-ranges[i]+1, 0); j <= min(i+ranges[i], n); ++j) 
            dp[j] = min(dp[j], dp[max(0, i-ranges[i])] + 1);
        for(int i = 0; i <= n; ++i) cout << dp[i] << " ";
        return dp[n] < n + 2 ? dp[n] : -1;
    }
};