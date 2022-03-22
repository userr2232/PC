const int INF = 1e9;
class Solution {
public:
    int maxChunksToSorted(vector<int>& A) {
        const int n = A.size();
        vector<pair<int,int>> max_min(n);
        int MX{-INF}, MN{INF};
        for(int i = 0; i < n; ++i) {
            auto& [mx, _] = max_min[i];
            if(i) mx = max(MX, A[i-1]);
            MX = max(mx, MX);
        }
        for(int i = n-1; i >= 0; --i) {
            auto& [_, mn] = max_min[i];
            mn = min(MN, A[i]);
            MN = min(mn, MN);
        }
        int ans{1};
        for(int i = n-1; i > 0; --i) {
            const auto [mx, mn] = max_min[i];
            if(mn >= mx) ans++;
        }
        return ans;
    }
};