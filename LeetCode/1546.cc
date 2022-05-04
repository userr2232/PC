class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int prefix{0}, prev_end{-1}, ans{0};
        for(int i = 0; i < nums.size(); ++i) {
            m[prefix] = i-1;
            prefix += nums[i];
            auto it = m.find(prefix-target);
            if(it != m.end() && it->second >= prev_end)
                ans++, prev_end = i;
        }
        return ans;
    }
};