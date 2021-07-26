class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32);
        f[0] = 1;
        f[1] = 2;
        for(int i = 2; i < 32; ++i) f[i] = f[i-1] + f[i-2];
        int ans{0};
        for(int i = 31; i >= 0; --i) {
            if(n & (1<<i)) {
                ans += f[i];
                if(prev = 1) { --ans; break; }
                prev = 1;
            }
            else prev = 0;
        }
        return ans + 1;
    }
};