
const int INF = 1e9;
class Solution {
    vector<int> memo;
    
    int dp(const vector<int>& coins, int amount) {
        int& ans = memo[amount];
        if(ans != -1) return ans;
        if(amount == 0) return ans = 0;
        ans = INF;
        for(auto coin : coins) if(coin <= amount)
            ans = min(ans, 1+dp(coins, amount-coin));
        return ans;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1, -1);
        dp(coins, amount);
        return memo[amount] == INF ? -1 : memo[amount];
    }
};