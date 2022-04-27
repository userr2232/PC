class SparseVector {
    vector<pair<int,int>> sparse_vector;
public:
    
    SparseVector(vector<int> &nums) {
        const int n = nums.size();
        for(int i = 0; i < n; ++i) if(auto&& num = nums[i]; num != 0)
            sparse_vector.emplace_back(i, num);
    }
    
    size_t size() {
        return sparse_vector.size();
    }
    
    pair<int,int> get(int i) {
        return sparse_vector[i];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i{0}, j{0};
        int ans{0};
        while(i < this->size() && j < vec.size()) {
            auto [i_idx, i_val] = sparse_vector[i];
            auto [j_idx, j_val] = vec.get(j);
            if(i_idx == j_idx) ans += i_val * j_val, ++i, ++j;
            else if(i_idx < j_idx) ++i;
            else ++j;
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);