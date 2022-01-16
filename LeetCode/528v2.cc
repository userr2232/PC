class Solution {
    vector<int> accum;
    mt19937 generator;
public:
    Solution(vector<int>& w): accum(w), generator(chrono::steady_clock::now().time_since_epoch().count()){
        for(int i = 1; i < w.size(); ++i) accum[i] += accum[i-1];
    }
    
    int pickIndex() {
        auto target = uniform_real_distribution<double>(0, accum.back())(generator);
        return upper_bound(accum.begin(), accum.end(), target) - accum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */