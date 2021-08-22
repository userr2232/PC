class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        int ans{0};
        for(int i = 1; i < s.length(); ++i) {
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    dp[i] = (i-2 >= 0 ? dp[i-2] : 0) + 2;
                }
                else if(i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '(') {
                    dp[i] = dp[i-1] + (i-1-dp[i-1]-1 >= 0 ? dp[i-dp[i-1]-2] : 0) + 2;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};