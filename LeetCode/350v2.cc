class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mm1, mm2;
        for(auto num : nums1) mm1[num]++;
        for(auto num : nums2) mm2[num]++;
        vector<int> ans;
        for(auto [num, count] : mm1) {
            for(int i = 0; i < count; ++i)
                if(mm2[num]) {
                    ans.emplace_back(num);
                    --mm2[num];
                }
            else break;
        }
        return ans;
    }
};