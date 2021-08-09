class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<tuple<int,int,int>> s;
        for(int k = nums.size()-1; k >= 2; --k) {
            for(int j = k-1; j >= 1; --j) {
                auto it = lower_bound(nums.begin(), nums.begin()+(j), -(nums[k]+nums[j]));
                if(it == nums.begin()+j) continue;
                if(*it + nums[j] + nums[k] == 0) s.insert({*it,nums[j],nums[k]});
            }
        }
        vector<vector<int>> ans(s.size());
        int i = 0;
        for(auto t : s) {
            int x, y, z;
            tie(x, y, z) = t;
            ans[i++] = {x,y,z};
        }
        return ans;
    }
};