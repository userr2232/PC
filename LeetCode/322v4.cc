class Solution {
    const int INF = 2e9;
    
    int dp(int i, int amount, vector<int> const& coins, vector<vector<int>>& memo) {
        if(i == coins.size()) {
            if(amount == 0) return 0;
            return INF;
        }
        auto&& ans = memo[i][amount];
        if(ans != -1) return ans;
        ans = dp(i+1, amount, coins, memo);
        if(amount >= coins[i]) ans = min(ans, 1+dp(i, amount-coins[i], coins, memo));
        return ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount+1, -1));
        return dp(0, amount, coins, memo) == INF ? -1 : memo[0][amount];
    }
};