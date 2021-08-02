class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = 2e9;
        int maxprofit = 0;
        for(const int& price : prices) {
            minprice = min(price, minprice);
            maxprofit = max(price-minprice, maxprofit);
        }
        return maxprofit;
    }
};