class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        const int n = nums.size();
        int ans{0};
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) {
                if(q.empty() || (q.size() & 1) == 0) {
                    q.emplace(i+k-1);
                    ans++;
                }
            }
            else {
                if(q.size() & 1) {
                    q.emplace(i+k-1);
                    ans++;
                }
            }
            if(!q.empty() && i >= q.front()) q.pop();
        }
        return q.empty() ? ans : -1;
    }
};