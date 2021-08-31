class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int l = (m+n+1) / 2;
        int lo = max(0, l-n), hi = min(l, m);
        while(lo <= hi) {
            int x = (lo+hi)/2;
            int y = l-x;
            if(y < n && x > 0) {
                if(nums1[x-1] > nums2[y]) {
                    hi = x-1;
                    continue;
                } 
            }
            if(x < m && y > 0) {
                if(nums2[y-1] > nums1[x]) {
                    lo = x+1;
                    continue;
                }
            }
            int lmax = x == 0 ? nums2[y-1] : y == 0 ? nums1[x-1] : max(nums1[x-1], nums2[y-1]);
            if((m+n)%2) return lmax;
            int rmin = x == m ? 
                        y == n ?
                            x == 0 ? nums2[y-1] : nums1[x-1] :
                            nums2[y] :
                        y == n ? 
                            nums1[x] : 
                            min(nums1[x], nums2[y]);
            return 0.5*(lmax+rmin);
        }
        return 0;
    }
};