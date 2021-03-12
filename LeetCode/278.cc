class Solution {
public:
    int firstBadVersion(int n) {
        long low{1}, high{n};
        long mid{(low + high) / 2};
        while(low < high) {
            if(isBadVersion(mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
            mid = (low + high) / 2;
        }
        return mid;
    }
};