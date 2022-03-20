class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int x{0}, y{1};
        int ans;
        for(int i = 2; i <= n; ++i) {
            ans = x + y;
            x = y;
            y = ans;
        }
        return ans;
    }
};