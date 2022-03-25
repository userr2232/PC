class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        vector<int>::iterator start{nums.begin()}, end{nums.end()};
        while(distance(start, end) > 1) {
            int n = distance(start, end);
            vector<int>::iterator mid = next(start, n >> 1);
            if(*mid == *next(mid)) {
                if(distance(start, mid) & 1) end = mid;
                else start = next(mid, 2);
            }
            else if(*mid == *prev(mid)) {
                if(distance(next(mid), end) & 1) start = next(mid);
                else end = prev(mid);
            }
            else return *mid;
        }
        return *start;
    }
};