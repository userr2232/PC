class Solution {    
public:
    int maxProfit(vector<int>& prices) {
        int buy_profit = -2e9, sell_profit = 0, profit_with_cooldown = 0, previous_profit = 0;
        for(auto&& price : prices) {
            sell_profit = buy_profit + price;
            buy_profit = max(buy_profit, profit_with_cooldown-price);
            profit_with_cooldown = max(profit_with_cooldown, previous_profit);
            previous_profit = sell_profit;
        }
        return max(sell_profit, profit_with_cooldown);
    }
};