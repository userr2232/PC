class Solution {
    void generate(vector<int> const& nums, vector<vector<int>>& ans, vector<int>&& current = {}, int i = 0) {
        if(i == nums.size()) {
            ans.emplace_back(current.begin(), current.end());
            return;
        }
        current.emplace_back(nums[i]);
        generate(nums, ans, forward<vector<int>>(current), i+1);
        current.pop_back();
        while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        generate(nums, ans, forward<vector<int>>(current), i+1);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        generate(nums, ans);
        return ans;
    }
};