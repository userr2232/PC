class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i{0};
        vector<vector<int>> ans;
        while(i < intervals.size() && intervals[i][1] < newInterval[0])
            ans.emplace_back(intervals[i++]);
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        ans.emplace_back(newInterval);
        while(i < intervals.size()) ans.emplace_back(intervals[i++]);
        return ans;
    }
};