class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i{0}, j{0}, sum{0}, ans = 1e9;
        const int n = nums.size();
        while(j < n) {
            sum += nums[j];
            while(sum >= target) {
                ans = min(ans, j-i+1);
                sum -= nums[i++];
            }
            ++j;
        }
        return ans == 1e9 ? 0 : ans;
    }
};