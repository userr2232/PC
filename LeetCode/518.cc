class Solution {
    vector<vector<int>> memo;
    
    int dp(int amount, const vector<int>& coins, int i = 0) {
        if(i == coins.size()) {
            if(amount == 0) return 1;
            return 0;
        }
        int& ans = memo[i][amount];
        if(ans != -1) return ans;
        ans = 0;
        if(amount >= coins[i])
            ans = dp(amount, coins, i+1) + dp(amount-coins[i], coins, i);
        else
            ans = dp(amount, coins, i+1);
        return ans;
    }
    
public:
    int change(int amount, vector<int>& coins) {
        const int n = coins.size();
        memo.assign(n, vector<int>(amount+1, -1));
        return dp(amount, coins);
    }
};