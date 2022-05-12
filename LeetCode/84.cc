class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        const int n = heights.size();
        int last_popped_index{0}, max_area{0};
        for(int i = 0; i < n; ++i) {
            auto&& height = heights[i];
            bool popped{false};
            while(!st.empty() && st.top().second > height) {
                popped = true;
                auto [idx, other_height] = st.top();
                st.pop();
                max_area = max(max_area, (i-idx)*other_height);
                last_popped_index = idx;
            }
            if(st.empty() || st.top().second < height) st.emplace(popped ? last_popped_index : i, height);
        }
        while(!st.empty()) {
            auto [idx, height] = st.top();
            st.pop();
            max_area = max(max_area, (n-idx)*height);
        }
        return max_area;
    }
};