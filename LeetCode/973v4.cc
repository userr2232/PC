class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>> max_heap;
        for(auto&& point : points) {
            double dist = hypot(point[0], point[1]);
            max_heap.emplace(dist, make_pair(point[0], point[1]));
            if(max_heap.size() > k) max_heap.pop();
        }
        vector<vector<int>> ans;
        while(!max_heap.empty()) {
            auto [_, point] = max_heap.top();
            max_heap.pop();
            ans.push_back({point.first, point.second});
        }
        return ans;
    }
};