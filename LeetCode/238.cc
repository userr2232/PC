class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 0);
        int whole_product = 1;
        int num_zeros{0}, zero_idx{0};
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if(num != 0)
                whole_product *= num; 
            if(num == 0) { 
                num_zeros++;
                zero_idx = i;
            }
            if(num_zeros > 1)
                return answer;
        }
        
        if(num_zeros) {
            answer[zero_idx] = whole_product;
            return answer;
        }
        for(int i = 0; i < nums.size(); ++i)
            answer[i] = whole_product / nums[i];
        return answer;
    }
};