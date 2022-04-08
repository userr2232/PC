class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int prev_end{-1};
        for(const auto& interval : intervals) {
            if(interval[0] < prev_end) return false;
            prev_end = interval[1];
        }
        return true;
    }
};