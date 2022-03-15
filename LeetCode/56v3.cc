class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0] || (!(rhs[0] < lhs[0]) && lhs[1] > rhs[1]);
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> v;
        v.emplace_back(intervals[0]);
        for(auto& interval : intervals) {
            auto& current = v.back();
            if(interval[0] <= current[1]) current[1] = max(interval[1], current[1]);
            else v.emplace_back(move(interval));
        }
        return v;
    }
};