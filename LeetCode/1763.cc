class Solution {
    bool is_nice(string const& str) {
        vector<bool> lower(26, false), upper(26, false);
        for(auto&& c : str) {
            if(c >= 'A' && c <= 'Z') upper[c-'A'] = true;
            else lower[c-'a'] = true;
        }
        for(int i = 0; i < 26; ++i)
            if(lower[i] != upper[i]) return false;
        return true;
    }
    
public:
    string longestNiceSubstring(string s) {
        for(int l = s.length(); l >= 2; --l) {
            for(int i = 0; i+l <= s.length(); ++i) {
                auto&& str = s.substr(i, l);
                if(is_nice(str)) return str;
            }
        }
        return "";
    }
};