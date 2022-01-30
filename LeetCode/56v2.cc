class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0]; };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> cur = intervals[0];
        vector<vector<int>> ans;
        const auto n = intervals.size();
        for(int i = 0; i < n; ++i) {
            const auto& interval = intervals[i];
            if(cur[1] < interval[0]) {
                ans.emplace_back(cur);
                cur = interval;
            }
            else {
                cur[1] = max(cur[1], interval[1]);
            }
            if(i == n-1) ans.emplace_back(cur);
        }
        return ans;
    }
};