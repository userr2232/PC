class Solution {
    vector<vector<pair<bool,bool>>> memo;
    
    bool isMatch(int i, int j, const string& s, const string& p) {
        if(i == s.length() || j == p.length()) {
            if(i == s.length()) {
                if(j == p.length()) return true;
                if(p[j] == '*') return isMatch(i, j+1, s, p);
                return false;
            }
            return false;
        }
        auto& [valid, ans] = memo[i][j];
        if(valid) return ans;
        valid = true;
        if(p[j] == '?' || p[j] == s[i]) return ans = isMatch(i+1, j+1, s, p);
        else if(p[j] != '*') return ans = p[j] == s[i];
        for(int i_prime = i; i_prime <= s.length(); ++i_prime) {
            ans = ans || isMatch(i_prime, j+1, s, p);
            if(ans) return ans;
        }
        return false;
    }
    
public:
    bool isMatch(string s, string p) {
        memo.assign(s.length(), vector<pair<bool,bool>>(p.length(), {false, false}));
        return isMatch(0, 0, s, p);
    }
};