class Solution {
    bool intersect(vector<int> const& lhs, vector<int> const& rhs) {
        return !(lhs[0] > rhs[1] || lhs[1] < rhs[0]);
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int inserted{false};
        for(auto&& interval : intervals) {
            if(intersect(interval, newInterval)) {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
            else if(interval[0] > newInterval[1]) {
                if(!inserted) {
                    inserted = true;
                    ans.emplace_back(newInterval);   
                }
                ans.emplace_back(interval);
            }
            else ans.emplace_back(interval);
        }
        if(!inserted) ans.emplace_back(newInterval);
        return ans;
    }
};