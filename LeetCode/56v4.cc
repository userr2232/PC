class Solution {
    bool overlaps(const vector<int>& a, const vector<int>& b) {
        if(a[1] < b[0] || a[0] > b[1]) return false;
        return true;
    }
    
    void merge(vector<int>& a, const vector<int>& b) {
        a[0] = min(a[0], b[0]);
        a[1] = max(a[1], b[1]);
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] > rhs[1];
        };
        
        sort(intervals.begin(), intervals.end(), cmp);
        if(intervals.empty()) return {};
        vector<int> current = intervals[0];
        vector<vector<int>> ans;
        for(auto& interval : intervals) {
            if(overlaps(current, interval)) merge(current, interval);
            else ans.emplace_back(move(current)), current = interval;
        }
        ans.emplace_back(current);
        return ans;
    }
};