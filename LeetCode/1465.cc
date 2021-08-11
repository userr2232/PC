class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int prev = 0;
        int vmax = verticalCuts.size() ? 0 : w;
        for(auto vcut : verticalCuts) {
            vmax = max(vmax, vcut-prev);
            prev = vcut;
        }
        vmax = max(vmax, w-prev);
        prev = 0;
        int hmax = horizontalCuts.size() ? 0 : h;
        for(auto hcut : horizontalCuts) {
            hmax = max(hmax, hcut-prev);
            prev = hcut;
        }
        hmax = max(hmax, h-prev);
        return (1LL*hmax*vmax)%((int)1e9+7);
    }
};