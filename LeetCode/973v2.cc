class Solution {
    typedef vector<int> vi;
    typedef pair<double,int> ii;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<ii> s;
        for(int i = 0; i < points.size(); ++i) {
            const auto& point = points[i];
            const auto& x = point[0];
            const auto& y = point[1];
            s.emplace(x*x+y*y, i);
        }
        vector<vector<int>> v(k, vi(2));
        int c{0};
        for(const auto& [_, point_idx] : s) {
            v[c++] = points[point_idx];
            if(c == k) break;
        }
        return v;
    }
};