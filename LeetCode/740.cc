class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> freqs;
        for(const auto& num : nums) freqs[num]++;
        int used_last_one{0}, did_not_use_last_one{0}, prev{0};
        for(const auto& [num, freq] : freqs) {
            int m = max(used_last_one, did_not_use_last_one);
            if(num-1 == prev) {
                used_last_one = num * freq + did_not_use_last_one;
                did_not_use_last_one = m;
            }
            else {
                used_last_one = num * freq + m;
                did_not_use_last_one = m;
            }
            prev = num;
        }
        return max(used_last_one, did_not_use_last_one);
    }
};