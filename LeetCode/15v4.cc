class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(i && nums[i] == nums[i-1]) continue;
            int j{i+1}, k{n-1};
            int prev_j{i};
            while(j < k) {
                if(prev_j > i && nums[j] == nums[prev_j]) {
                    j++;
                    continue;
                }
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    prev_j = j;
                    j++, k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        return ans;
    }
};