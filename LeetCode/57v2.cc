class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = newInterval[0], end = newInterval[1];
        int merged_start = start, merged_end = end;
        bool emplaced{false};
        vector<vector<int>> ans;
        for(auto& interval : intervals) {
            int local_start = interval[0], local_end = interval[1];
            if(local_end < merged_start) ans.emplace_back(interval);
            else if(local_start > merged_end) {
                if(!emplaced) ans.push_back({merged_start, merged_end}), emplaced = true;
                ans.emplace_back(interval);
            }
            else merged_start = min(merged_start, local_start), merged_end = max(merged_end, local_end);
        }
        if(!emplaced) ans.push_back({merged_start, merged_end});
        return ans;
    }
};