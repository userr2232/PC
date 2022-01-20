class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) return 1/x * myPow(1/x, -(++n));
        bool odd = n % 2;
        n /= 2;
        auto y = myPow(x, n);
        return (odd ? x : 1) * y * y;
    }
};