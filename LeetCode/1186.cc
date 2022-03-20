class Solution {
public:
    int maximumSum(vector<int>& A) {
        int suffix_no_del = A[0];
        int suffix_w_del = 0;
        int ans{A[0]};
        const int n = A.size();
        for(int i = 1; i < n; ++i) {
            suffix_w_del = max(suffix_w_del + A[i], suffix_no_del);
            suffix_no_del = max(suffix_no_del + A[i], A[i]);
            ans = max({ans, suffix_no_del, suffix_w_del});
        }
        return ans;
    }
};