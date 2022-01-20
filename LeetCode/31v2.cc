class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it = is_sorted_until(nums.rbegin(), nums.rend());
        if(it != nums.rend()) swap(*upper_bound(nums.rbegin(), it, *it), *it);
        reverse(nums.rbegin(), it);
    }
};