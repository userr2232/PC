class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> L(nums.size());
        int k{0};
        for(auto&& num : nums) {
            int pos = distance(L.begin(), lower_bound(L.begin(), next(L.begin(), k), num));
            L[pos] = num;
            if(pos == k) ++k;
        }
        return k;
    }
};