class Solution {
    int find_pivot(const vector<int>& nums) {
        int n = nums.size();
        int x = n-1;
        int k = nums[0];
        for(int b = n/2; b >= 1; b /= 2)
            while(x-b >= 0 && nums[x-b] < k) x -= b;
        return x;
    }
    
public:
    int search(vector<int>& nums, int target) {
        bool rotated = nums[0] > nums[nums.size()-1];
        vector<int>::iterator b, e;
        if(!rotated) {
            b = nums.begin(), e = nums.end();
        }
        else {
            int pivot_idx = find_pivot(nums);
            if(target >= nums[0]) b = nums.begin(), e = nums.begin()+pivot_idx;
            else b = nums.begin()+pivot_idx, e = nums.end();
        }
        auto it = lower_bound(b, e, target);
        if(it == e || *it != target) return -1;
        return distance(nums.begin(), it);
    }
};