class Solution {
    int dp(int i, int amount, vector<int> const& coins, vector<vector<int>>& memo) {
        if(i == coins.size()) {
            if(amount == 0) return 1;
            return 0;
        }
        int& ans = memo[i][amount];
        if(ans != -1) return ans;
        ans = dp(i+1, amount, coins, memo);
        if(coins[i] <= amount) ans += dp(i, amount-coins[i], coins, memo);
        return ans;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount+1, -1));
        return dp(0, amount, coins, memo);
    }
};