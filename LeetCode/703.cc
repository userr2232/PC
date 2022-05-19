class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> min_heap;
public:
    KthLargest(int k, vector<int>& nums) {
        if(k <= 0) throw invalid_argument("k must be positive");
        this->k = k;
        for(auto&& num : nums) {
            min_heap.emplace(num);
            if(min_heap.size() > k) min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.emplace(val);
        if(min_heap.size() > k) min_heap.pop();
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */