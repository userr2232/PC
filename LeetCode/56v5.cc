class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] < rhs[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int prev_end{-1};
        vector<vector<int>> ans;
        for(auto&& interval : intervals) {
            int start = interval[0];
            if(start > prev_end) {
                ans.emplace_back(interval);
                prev_end = interval[1];
            }
            else prev_end = ans.back()[1] = max(ans.back()[1], interval[1]);
        }
        return ans;
    }
};