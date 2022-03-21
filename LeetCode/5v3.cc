class Solution {
    vector<vector<bool>> dp;
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        dp.assign(n, vector<bool>(n, false));
        int longest{1};
        for(int i = 0; i < n; ++i) {
            dp[i][i] = true;
            if(i && s[i-1] == s[i]) dp[i-1][i] = true, longest = max(longest, 2);
        }
        for(int l = 3; l <= n; ++l) for(int i = 0; i < n; ++i) if(i+l <= n) {
            if(dp[i+1][i+l-2] && s[i] == s[i+l-1])
                dp[i][i+l-1] = true, longest = l;
        }
        for(int i = 0; i < n; ++i) if(i+longest <= n) {
            if(dp[i][i+longest-1]) return s.substr(i, longest);
        }
        return s;
    }
};