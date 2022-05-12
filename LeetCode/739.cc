class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        const int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.emplace(i);
        }
        return ans;
    }
};