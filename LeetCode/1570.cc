class SparseVector {
private:
    size_t _size{0};
    size_t _real_size{0};
public:
    vector<pair<int,int>> idx_val;
    
    SparseVector(vector<int> &nums) {
        _size = nums.size();
        for(const auto& num : nums) if(num) ++_real_size;
        idx_val.resize(_real_size);
        int j{0};
        for(int i = 0; i < _size; ++i)
            if(nums[i]) idx_val[j++] = {i, nums[i]};
    }
    
    size_t size() { return _size; }
    
    size_t num_elements() { return _real_size; }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i{0}, j{0};
        int ans{0};
        for(int k = 0; k < vec.size(); ++k) {
            auto [idx_i, val_i] = (i < num_elements() ? idx_val[i] : pair<int,int>(0,0));
            auto [idx_j, val_j] = (j < vec.num_elements() ? vec.idx_val[j] : pair<int,int>(0,0));
            if(idx_i == k) ++i;
            else val_i = 0;
            if(idx_j == k) ++j;
            else val_j = 0;
            ans += val_i*val_j;
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);