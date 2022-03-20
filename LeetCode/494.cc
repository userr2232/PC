class Solution {
    int n, total, target;
    vector<vector<int>> memo;
    
public:
    int find(int i, int current, const vector<int>& nums) {
        if(i == n) {
            if(current == target) return 1;
            return 0;
        }
        if(auto& ans = memo[i][current+total]; ans != -1) return ans;
        else
            return ans = find(i+1, current+nums[i], nums) + find(i+1, current-nums[i], nums);   
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        this->target = target;
        memo.assign(n, vector<int>(2*total+1, -1));
        return find(0, 0, nums);
    }
};