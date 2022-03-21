class Solution {
    vector<vector<int>> memo;
    
    int dp(int i, int j, const string& s, const string& t) {
        if(i == s.length() || j == t.length()) {
            if(j == t.length()) return 1;
            return 0;
        }
        int& ans = memo[i][j];
        if(ans != -1) return ans;
        if(s[i] == t[j]) return ans = dp(i+1, j+1, s, t) + dp(i+1, j, s, t);
        return ans = dp(i+1, j, s, t);
    }
    
public:
    int numDistinct(string s, string t) {
        memo.assign(s.size(), vector<int>(t.size(), -1));
        return dp(0, 0, s, t);
    }
};