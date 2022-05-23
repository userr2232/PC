class Solution {
    void generate(vector<int> const& candidates, const int target, vector<vector<int>> & ans, vector<int>&& current = {}, int sum = 0, int i = 0) {
        if(i == candidates.size()) {
            if(sum == target) ans.emplace_back(current.begin(), current.end());
            return;
        }
        if(candidates[i] + sum <= target) {
            current.emplace_back(candidates[i]);
            generate(candidates, target, ans, forward<vector<int>>(current), sum + candidates[i], i+1);
            current.pop_back();
        }
        while(i+1 < candidates.size() && candidates[i+1] == candidates[i]) ++i;
        generate(candidates, target, ans, forward<vector<int>>(current), sum, i+1);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        generate(candidates, target, ans);
        return ans;
    }
};