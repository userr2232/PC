class Solution {
    deque<int> deq;
    vector<int> nums, ans;
    int k;
public:
    void clear(int i) {
        if(!deq.empty() && deq.front() <= i-k) deq.pop_front();
        while(!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
    }
    
    void push(int i) {
        deq.push_back(i);
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        for(int i = 0; i < k; ++i) clear(i), push(i);
        ans.push_back(nums[deq.front()]);
        for(int i = k; i < nums.size(); ++i) clear(i), push(i), ans.push_back(nums[deq.front()]);
        return ans;
    }
};