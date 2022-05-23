class Solution {
    bool is_palindrome(string&& str) {
        if(str.length() <= 1) return true;
        if(str.length() == 2) return str[0] == str[1];
        const int n = str.length();
        for(int i = 0; i < n/2; ++i)
            if(str[i] != str[n-i-1]) return false;
        return true;
    }
    
    void generate(vector<vector<string>>& ans, string const& s, int i = 0, vector<string>&& current = {}) {
        if(i == s.length()) {
            if(!current.empty()) ans.emplace_back(current.begin(), current.end());
            return;
        }
        const int n = s.length();
        for(int l = 1; l <= n-i+1; ++l) {
            if(is_palindrome(forward<string>(s.substr(i, l)))) {
                current.emplace_back(s.substr(i, l));
                generate(ans, s, i+l, forward<vector<string>>(current));
                current.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        generate(ans, s);
        return ans;
    }
};