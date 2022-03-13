class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        size_t n = intervals.size();
        vector<int> start(n), end(n);
        for(int i = 0; i < intervals.size(); ++i) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i{0}, j{0};
        int ans{0}, count{0};
        while(j < n) {
            if(i < n && start[i] < end[j]) count++, i++;
            else count--, j++;
            ans = max(ans, count);
        }
        return ans;
    }
};