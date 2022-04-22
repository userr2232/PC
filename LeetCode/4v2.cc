class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        int left_length = n + m + 1 >> 1;
        int lo{max(0, left_length-n)}, hi{min(m, left_length)};
        while(lo <= hi) {
            int x = lo + hi >> 1;
            int y = left_length - x;
            if(x > 0 && y < n && nums1[x-1] > nums2[y]) {
                hi = x-1;
                continue;
            }
            if(y > 0 && x < m && nums2[y-1] > nums1[x]) {
                lo = x+1;
                continue;
            }
            bool odd = m + n & 1;
            int left_max = x > 0 && y > 0 ? max(nums1[x-1], nums2[y-1]) : x > 0 ? nums1[x-1] : nums2[y-1];
            if(odd) return left_max;
            int right_min = x < m && y < n ? min(nums1[x], nums2[y]) : x < m ? nums1[x] : nums2[y];
            return 0.5 * (left_max + right_min);
        }
        return 0;
    }
};