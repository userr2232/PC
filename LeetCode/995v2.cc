class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        const int n = nums.size();
        int ans{0};
        for(int i = 0; i < n; ++i) {
            auto&& num = nums[i];
            bool odd = q.size() & 1;
            if(num == 0 && !odd || num == 1 && odd)
                q.emplace(i+k-1), ans++;
            if(!q.empty() && q.front() == i) q.pop();
        }
        return q.empty() ? ans : -1;
    }
};