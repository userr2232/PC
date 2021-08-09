class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prev_i{-1};
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            if(prev_i >= 0 && nums[i] == nums[prev_i]) continue;
            int lo{i+1}, prev_lo{-1}, hi = nums.size()-1;
            while(lo < hi) {
                if(prev_lo >= 0 && nums[lo] == nums[prev_lo]) { lo++; continue; }
                int sum = nums[i]+nums[lo]+nums[hi];
                if(sum == 0) ans.push_back({nums[i],nums[lo],nums[hi]}), prev_lo = lo, lo++, hi--;
                else if(sum < 0) lo++;
                else hi--;
            }
            prev_i = i;
        }
        return ans;
    }
};