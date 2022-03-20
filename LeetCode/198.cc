class Solution {
public:
    int rob(vector<int>& A) {
        const int n = A.size();
        if(n == 1) return A[0];
        int x{A[0]}, y{max(A[0], A[1])};
        if(n <= 2) return max(x, y);
        int ans;
        for(int i = 2; i < n; ++i) {
            ans = max(x+A[i], y);
            int xmp = x;
            x = max(x, y);
            y = max(y, xmp + A[i]);
        }
        return ans;
    }
};