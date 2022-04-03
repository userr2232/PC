class Solution {
    vector<int> memo;
    
    int dp(int i, const string& s) {
        int& ans = memo[i];
        if(ans != -1) return ans;
        if(i == s.length()) return ans = 1;
        if(i > s.length()) return ans = 0;
        if(s[i] == '0') return ans = 0;
        if(s[i] == '1') return ans = dp(i+1, s) + dp(i+2, s);
        if(s[i] == '2') {
            if(i+1 < s.length()) {
                return ans = dp(i+1, s) + (s[i+1] <= '6' ? dp(i+2, s) : 0);
            }
            else return ans = dp(i+1, s);
        }
        return ans = dp(i+1, s);
    }
    
public:
    int numDecodings(string s) {
        memo.assign(s.length()+2, -1);
        return dp(0, s);
    }
};