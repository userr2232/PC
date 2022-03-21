class Solution {
    int n;
    vector<int> memo;
    
    int LIS(int i, vector<int>& nums) {
        if(int& ans = memo[i]; ans != -1) return ans;
        else {
            ans = 1;
            for(int j = 0; j < i; ++j) if(nums[j] < nums[i])
                ans = max(ans, LIS(j, nums)+1);
            return ans;
        }
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        nums.emplace_back(1e5);
        n = nums.size();
        memo.assign(n, -1);
        return LIS(nums.size()-1, nums)-1;
    }
};