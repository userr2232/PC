class Solution {
    bool dp(int i, int j, int k, string const& s1, string const& s2, string const& s3, vector<vector<vector<int>>>& memo) {
        auto& ans = memo[i][j][k];
        if(ans != -1) return ans;
        if(k == s3.length()) return ans = 1;
        ans = 0;
        if(i < s1.length() && s1[i] == s3[k]) ans += dp(i+1, j, k+1, s1, s2, s3, memo);
        if(j < s2.length() && s2[j] == s3[k]) ans += dp(i, j+1, k+1, s1, s2, s3, memo);
        return ans;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length()) return false;
        vector<vector<vector<int>>> memo(s1.length()+1, vector<vector<int>>(s2.length()+1, vector<int>(s3.length()+1, -1)));
        return dp(0, 0, 0, s1, s2, s3, memo);
    }
};