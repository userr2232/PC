class Solution {
public:
    static bool greater(pair<int,int>interval1, pair<int,int>interval2) {
        return interval1.second > interval2.second;
    }
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int,int>> intervals2;
        for(auto interval : intervals) intervals2.push_back({interval[0],interval[1]});
        sort(intervals2.begin(), intervals2.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>,pair<int,int>)>> pq(greater);
        int ans{0};
        for(auto [start, end] : intervals2) {
            if(!pq.empty()) {
                auto [other_start, other_end] = pq.top();
                if(other_end > start) pq.push({start, end});
                else {
                    while(!pq.empty() && pq.top().second <= start) pq.pop();
                    pq.push({start, end});
                }
            }
            else pq.push({start, end});
            ans = max(ans, (int)pq.size());
        }
        return ans;
    }
};