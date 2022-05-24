class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int a{0}, b{nums[1]}, c{0};
        int d{nums[0]}, e{max(nums[0], nums[1])}, f{0};
        for(int i = 2; i < nums.size(); ++i) {
            c = max(a + nums[i], b);
            a = b;
            b = c;
            if(i+1 < nums.size()) {
                f = max(d + nums[i], e);
                d = e;
                e = f;
            }
            else f = max({d, e, f});
        }
        return max(c, f);
    }
};