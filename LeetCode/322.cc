class Solution {
    vector<int> coins;
    vector<int> memo;
    vector<bool> visited;
    const int INF = 2e9;
    
    int dp(int amount) {
        if(amount == 0) return 0;
        int& ans = memo[amount];
        if(visited[amount]) return ans;
        for(auto coin : coins) if(coin <= amount) ans = min(ans, 1+dp(amount-coin));
        visited[amount] = true;
        return ans;
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        this->coins = coins;
        memo.assign(amount+1, INF);
        visited.assign(amount+1, false);
        return dp(amount) == INF ? -1 : dp(amount);
    }
};