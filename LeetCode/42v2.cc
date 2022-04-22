class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_left(height.size(), 0);
        vector<int> max_right(height.size(), 0);
        const int n = height.size();
        for(int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i-1], height[i-1]);
        }
        for(int i = n-2; i >= 0; --i) {
            max_right[i] = max(max_right[i+1], height[i+1]);
        }
        int ans{0};
        for(int i = 1; i < n-1; ++i) {
            ans += max(min(max_left[i], max_right[i]) - height[i], 0);
        }
        return ans;
    }
};