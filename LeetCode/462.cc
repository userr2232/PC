class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans{0};
        int med = nums[nums.size()/2];
        for(auto& e : nums)
            ans += abs(e - med);
        return ans;
    }
};