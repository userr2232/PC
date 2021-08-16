class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans{0};
        for(int i = 2; i*(i+1)/2 <= n; ++i) {
            int rem = n - (i*(i+1))/2;
            if(rem/i*i == rem) ans++;
        }
        return ++ans;
    }
};