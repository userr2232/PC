class Solution {
public:
    bool isMatch(string s, string p) {
        s = "#" + s;
        p = "#" + p;
        vector<vector<bool>> dp(p.length()+1, vector<bool>(s.length()+1, false));
        dp[0][0] = true;
        for(int i = 1; i < p.length(); ++i) for(int j = 0; j < s.length(); ++j) {
            if(j > 0 && dp[i-1][j-1] && (s[j] == p[i] || p[i] == '?')) dp[i][j] = true;
            if(p[i] == '*' && dp[i-1][j]) for(; j < s.length(); ++j) dp[i][j] = true;
        }
        return dp[p.length()-1][s.length()-1];
    }
};