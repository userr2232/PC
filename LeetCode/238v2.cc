class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = vector<int>(nums.size(), 1);
        for(int i = 1; i < nums.size(); ++i)
            ans[i] = nums[i-1] * ans[i-1];
        int right{1};
        for(int i = static_cast<int>(nums.size())-1; i >= 0; --i) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};