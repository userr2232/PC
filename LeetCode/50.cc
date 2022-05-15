class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        auto sq_pow = n < 0 ? myPow(1/x, -(n >> 1)) : myPow(x, n >> 1);
        auto pow = sq_pow * sq_pow;
        return n & 1 ? pow * x : pow;
    }
};