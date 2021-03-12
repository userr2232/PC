class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int i = nums.size() - 2;
        while(i >= 0) {
            int j = i + 1;
            int j_min = j;
            for(; j < nums.size(); ++j) {
                if(nums[j] > nums[i]) {
                    if(nums[j_min] > nums[j]) {
                        j_min = j;
                    }
                }
            }
            if(nums[j_min] <= nums[i]) {
                i--;
            }
            else {
                swap(nums[i] , nums[j_min]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};