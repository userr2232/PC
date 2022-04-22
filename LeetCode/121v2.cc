class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i{0}, j{0}, ans{0};
        for(; j < prices.size(); ++j) {
            if(prices[j] < prices[i]) i = j;
            ans = max(ans, prices[j]-prices[i]);
        }
        return ans;
    }
};