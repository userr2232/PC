class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n-1, 0);
        int ans{0};
        for(int start = 0; start < min(n, 2); ++start) {
            int end = start+n-1;
            int j{0};
            dp[j] = nums[start], ans = max(ans, dp[j++]);
            if(start+j < end) dp[j] = max(nums[start+j-1], nums[start+j]), ans = max(ans, dp[j++]);
            while(j < n-1) {
                dp[j] = max(dp[j-1], dp[j-2]+nums[start+j]);
                ans = max(ans, dp[j++]);
            }
        }
        return ans;
    }
};