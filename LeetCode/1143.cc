class Solution {
    vector<vector<int>> memo;
    
    int dp(int i, int j, const string& text1, const string& text2) {
        if(i == text1.size() || j == text2.size()) return 0;
        int& ans = memo[i][j];
        if(ans != -1) return ans;
        if(text1[i] == text2[j]) ans = 1+dp(i+1, j+1, text1, text2);
        else ans = max(dp(i+1, j, text1, text2), dp(i, j+1, text1, text2));
        return ans;
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));
        return dp(0, 0, text1, text2);
    }
};