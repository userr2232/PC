class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int accum{0}, prev_accum{0};
        for(int i = 0; i < nums.size(); ++i) {
            const auto& num = nums[i];
            accum += num;
            auto x = s.find(accum % k);
            if(x != s.end()) {
                return true;
            }
            s.emplace(prev_accum%k);
            prev_accum = accum;
        }
        return false;
    }
};