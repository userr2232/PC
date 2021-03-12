class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) { 
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == 0 && nums[i-1] == 0) return true;
        }
        if(k == 0) return false;
        if(abs(k) == 1 && nums.size() >= 2) return true;
        vector<int> prefix_sum(nums.size() + 1, 0);
        for(int i = 1; i < prefix_sum.size(); ++i) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        }
        
        map<int, int> find_i;
        for(int j = 0; j < prefix_sum.size(); ++j) {
            auto mod = prefix_sum[j] % k;
            if(mod == 0 && j >= 2) return true;
            if(!find_i[mod]) {
                find_i[mod] = j;
            }
            else {
                auto i = find_i[mod];
                if(i <= j - 2) return true;
            }
        }
        return false;
    }
};