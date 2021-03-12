class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multimap<int, int> mm;
        for(int i = 0; i < points.size(); ++i) {
            auto point = points[i];
            mm.insert({point[0]*point[0] + point[1]*point[1], i});
        }
        vector<vector<int>> res;
        int i = 0;
        for(auto [key, idx] : mm) {
            if(i++ == k) return res;
            res.push_back({points[idx][0], points[idx][1]});
        }
        return res;
    }
};