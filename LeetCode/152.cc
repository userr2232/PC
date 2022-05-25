class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) throw invalid_argument("vector cannot be empty.");
        int ans{nums[0]};
        int max_prod{1}, min_prod{1};
        for(auto&& num : nums) {
            auto tmp = max_prod;
            max_prod = max({tmp*num, min_prod*num, num});
            min_prod = min({min_prod*num, tmp*num, num});
            ans = max(ans, max_prod);
            max_prod = max_prod == 0 ? 1 : max_prod;
            min_prod = min_prod == 0 ? 1 : min_prod;
        }
        return ans;
    }
};