class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int ans{0}, prev_end{intervals[0][1]};
        for(int i = 1; i < intervals.size(); ++i) {
            const vector<int>& interval = intervals[i];
            if(prev_end > interval[0]) {
                ans++;
                prev_end = min(prev_end, interval[1]);
            }
            else prev_end = interval[1];
        }
        return ans;
    }
};