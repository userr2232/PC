class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans{(int)-(1LL<<31)}, sum{0};
        for(auto num : nums) {
            sum += num;
            ans = max(ans, sum);
            sum = max(0, sum);
        }
        return ans;
    }
};