class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix{0};
        unordered_map<int,int> m;
        int ans{0};
        for(auto&& num : nums) {
            m[prefix]++;
            prefix += num;
            if(auto it = m.find(prefix-k); it != m.end())
                ans += it->second;
        }
        return ans;
    }
};