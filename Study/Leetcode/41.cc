class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n;) {
            long long j = nums[i]-1LL;
            if(j >= 0 && j < n && nums[i] != nums[j]) swap(nums[i], nums[j]);
            else ++i;
        }
        for(int i = 0; i < n; ++i) if(nums[i] != i+1) return i+1;
        return n+1;
    }
};