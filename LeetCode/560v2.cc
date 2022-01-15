class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sum_count;
        sum_count[0] = 1;
        int ans{0}, accum{0};
        for(const auto& num: nums) {
            accum += num;
            auto it = sum_count.find(accum-k);
            if(it != sum_count.end())
                ans += it->second;
            sum_count[accum] += 1;
        }
        return ans;
    }
};