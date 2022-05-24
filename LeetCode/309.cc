class Solution {
    
    int dp(int i, int selling, vector<int> const& prices, vector<vector<int>>& memo) {
        if(i >= prices.size()) return 0;
        int& ans = memo[i][selling];
        if(ans != -1) return ans;
        ans = dp(i+1, selling, prices, memo);
        if(selling)
            return ans = max(ans, prices[i] + dp(i+2, 1-selling, prices, memo));
        return ans = max(ans, -prices[i] + dp(i+1, 1-selling, prices, memo));
    }
    
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return dp(0, 0, prices, memo);
    }
};