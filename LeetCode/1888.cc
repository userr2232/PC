class Solution {
public:
    int minFlips(string s) {
        string a, b;
        const int n = s.length();
        for(int i = 0; i < n; ++i) {
            a += '0'+static_cast<int>(i&1);
            b += '0'+static_cast<int>(!(i&1));
        }
        string tmp_a = a;
        if(a[0] != a[n-1]) a += a, b += b;
        else a += b, b += tmp_a;
        s += s;
        int diff_a{0}, diff_b{0}, ans;
        for(int i = 0; i < n; ++i) {
            diff_a += s[i] != a[i];
            diff_b += s[i] != b[i];
        }
        ans = min(diff_a, diff_b);
        for(int i = n; i < (n << 1); ++i) {
            int prev = i - n;
            if(s[prev] != a[prev]) diff_a--;
            if(s[prev] != b[prev]) diff_b--;
            diff_a += s[i] != a[i];
            diff_b += s[i] != b[i];
            ans = min(ans, min(diff_a, diff_b));
        }
        return ans;
    }
};