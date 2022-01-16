class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto const comp = [&](const int& lhs, const int& rhs){ return lhs > rhs; };
        multiset<int, decltype(comp)> s(nums.begin(), nums.end(), comp);
        auto it = s.begin();
        return *next(it, k-1);
    }
};