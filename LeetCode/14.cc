class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        int n = str.length();
        int i{0};
        for(; i < n; ++i) {
            for(const string& s : strs) {
                if(i >= s.length()) { n = --i; break; }
                if(str[i] != s[i]) return str.substr(0,i);
            }
        }
        return str.substr(0,i);
    }
};