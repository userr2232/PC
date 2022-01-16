class Solution {
    typedef vector<int> vi;
    typedef pair<double,int> ii;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const auto dist = [](vector<int>& point) { return point[0]*point[0]+point[1]*point[1]; };
        sort(points.begin(), points.end(), [&](vector<int>& lhs, vector<int>& rhs) { return dist(lhs) < dist(rhs); });
        return {points.begin(), points.begin()+k};
    }
};