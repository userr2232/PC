class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int leftMax = nums[0];
        int possibleMax = nums[0];
        int length = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < leftMax) {
                length = i+1;
                leftMax = possibleMax;
            }
            else {
                possibleMax = max(possibleMax, nums[i]);
            }
        }
        return length;
    }
};