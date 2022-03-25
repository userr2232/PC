class Solution {
    int longest{0}, start{0};
    
    void expand(const string& s, int i, int length = 1) {
        int j = i+length-1;
        for(; i >= 0 && j < s.length() && s[i] == s[j]; ++j, --i) {
            if(j-i+1 > longest) start = i, longest = j-i+1;
        }
    }
    
public:
    string longestPalindrome(string s) {
        for(int i = 0; i < s.length(); ++i) {
            expand(s, i);
            if(i) expand(s, i-1, 2);
        }
        return s.substr(start, longest);
    }
};