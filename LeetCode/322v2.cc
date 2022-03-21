class Solution {
    const int INF = 2e9;
    
    vector<int> memo;
    vector<bool> visited;
    
    int dp(const vector<int>& coins, int amount) {
        if(int& ans = memo[amount]; ans != INF || visited[amount]) return ans;
        else {
            for(auto coin : coins) if(coin <= amount)
                ans = min(ans, 1+dp(coins, amount-coin));
            visited[amount] = true;
            return ans;
        }
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        memo.assign(amount+1, INF);
        visited.assign(amount+1, false);
        memo[0] = 0;
        dp(coins, amount);
        if(auto ans = memo[amount]; ans == INF)
            return -1;
        else return ans;
    }
};