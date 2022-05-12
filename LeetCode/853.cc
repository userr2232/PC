class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<pair<int,int>> cars(n);
        for(int i = 0; i < n; ++i) cars[i] = make_pair(position[i], speed[i]);
        sort(cars.begin(), cars.end());
        stack<pair<int,int>> st;
        for(int i = n-1; i >= 0; --i) {
            if(st.empty() || 1.0*(target-st.top().first) / st.top().second < 1.0 * (target-cars[i].first) / cars[i].second)
                st.emplace(cars[i]);
        }
        return st.size();
    }
};