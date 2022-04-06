class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum{0}, ans{0}, i{0};
        for(int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while(nums[j] * (j-i+1) - sum > k) sum -= nums[i++];
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};