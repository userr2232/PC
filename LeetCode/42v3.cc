class Solution {
public:
    int trap(vector<int>& height) {
        int left{0}, right{static_cast<int>(height.size())-1};
        int max_left{0}, max_right{0};
        int ans{0};
        while(left < right) {
            if(height[left] < height[right]) {
                max_left = max(max_left, height[left]);
                ans += max_left - height[left];
                left++;
            }
            else {
                max_right = max(max_right, height[right]);
                ans += max_right - height[right];
                right--;
            }
        }
        return ans;
    }
};