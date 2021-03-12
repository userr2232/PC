class Solution {
public:
    int trap(vector<int>& height) {
        unordered_map<int,int> left_max;
        unordered_map<int,int> right_max;
        int n{(int)height.size()}, answer{0};
        if(n <= 2) return 0;
        left_max[0] = 0;
        right_max[n-1] = 0;
        for(int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i-1], height[i-1]);
        }
        for(int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i+1], height[i+1]);
        }
        for(int i = 0; i < n; ++i) {
            answer += max(0, min(left_max[i], right_max[i]) - height[i]);
        }
        return answer;
    }
};