class Solution {
public:
    int longestValidParentheses(string s) {
        int left{0}, right{0};
        int n = s.length();
        int ans{0};
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') ++left;
            else {
                if(right < left) ++right;
                else right = 0, left = 0;
            }
            if(left == right) ans = max(ans, left+right);
        }
        left = 0, right = 0;
        for(int i = n-1; i >= 0; --i) {
            if(s[i] == '(') {
                if(left < right) ++left;
                else right = 0, left = 0;
            }
            else right++;
            if(left == right) ans = max(ans, left+right);
        }
        return ans;
    }
};