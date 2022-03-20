class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        int sum{0};
        for(const auto& num : nums) sum += num;
        if(sum & 1) return false;
        sum >>= 1;
        vector<bool> dp(sum+1, false), new_dp(sum+1, false);
        dp[0] = true;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= sum; ++j) if(dp[j] && j+nums[i] <= sum)
                new_dp[j+nums[i]] = true;
            dp = new_dp;
        }
        return dp[sum];
    }
};