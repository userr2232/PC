class Solution {
    void generate(vector<int> const& nums, vector<vector<int>>& ans, vector<int>&& current = {}, int i = 0) {
        if(i == nums.size()) {
            ans.emplace_back(current.begin(), current.end());
            return;
        }
        current.emplace_back(nums[i]);
        generate(nums, ans, forward<vector<int>>(current), i+1);
        current.pop_back();
        generate(nums, ans, forward<vector<int>>(current), i+1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        generate(nums, ans);
        return ans;
    }
};